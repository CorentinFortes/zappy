/*
** EPITECH PROJECT, 2023
** server.h
** File description:
** server.h
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/queue.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdbool.h>
#include <uuid/uuid.h>
#include <time.h>
#include <math.h>

#define ARG_COND ; optind < ac \
&& av[optind][0] != '-'; optind++
#define MAX_BODY_LENGTH 1024
enum state {
    DEAD,
    EGG,
    INCANTATION,
    ALIVE,
};

typedef struct inventory {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory;

typedef struct gui_player {
    int x;
    int y;
    int socket;
} gui_player;

typedef struct egg {
    int x;
    int y;
    int time;
    int level;
    int max_level;
} egg;

typedef struct player {
    int x;
    int y;
    int level;
    inventory *inv;
    int is_dead;
    char orientation;
    char *team_name;
    int socket;
    enum state state;
} player;

typedef struct tile {
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    player *player; // TODO: Change to get ALL players on the tile
} tile;

typedef struct client {
    int socket;
    char *uid;
    char *buffer;
    char *team_name;
    player *player;
    gui_player *gui_player;
    LIST_ENTRY(client) next;
} client_t;

typedef struct team {
    char *name;
    int max_clients;
    int clients;
    LIST_ENTRY(team) next;
} team_t;

extern LIST_HEAD(list_head, client) head;
extern LIST_HEAD(team_listhead, team) team_head;
typedef struct game {
    tile **map;
} game_t;

typedef struct task {
    char *cmd;
    int id;
    double time;
    client_t *client;
    LIST_ENTRY(task) next;
} task_t;
extern LIST_HEAD(task_listhead, task) task_head;

typedef struct server_s {
    int port;
    int width;
    int height;
    char **sname;
    int clientsNb;
    int freq;
    int socket;
    int task_id;
    int task_stack;
    struct list_head head;
    struct team_listhead team_head;
    struct task_listhead task_head;
    struct timespec server_time;
    client_t *clients;
    game_t *game;
    task_t *tasks;
    team_t *teams; // TODO: Implement teams when the server loads
} server_t;


// MISC
void print_help(void);
void fetch_arguments(server_t *s_infos, int arg, char **av, int ac);
void check_args(server_t *s_infos);
int my_arrlen(char **arr);
int *create_tuple(int x, int y);

// SERVER
server_t *create_server_struct(void);
void init_server(server_t *s_infos);
void add_client(server_t *s_infos);
void loop_server(server_t *s_infos);

// CLIENT
void add_client(server_t *s_infos);
client_t *generate_client(int socket);
void check_command(client_t *cli, server_t *s_infos);
void handle_client_data(server_t *s_infos, fd_set *readfds);
void generate_teams(server_t *server, struct team_listhead *team_head);
team_t *generate_team(char *name, int maxclient);
int commands(server_t *server, client_t *client, char *buffer);
int add_client_to_team(server_t *s_infos, char *team, client_t *cli);
int get_available_slots_in_team(server_t *s_infos, char *team);
int does_team_has_space(server_t *s_infos, char *team);
int does_team_exists(server_t *s_infos, char *team);
void remove_client_from_team(client_t *cli, server_t *s_infos);

// MAP
tile **generate_map(server_t *infos);
void fill_map(server_t infos, tile **map);

// MAP RESOURCES
int *get_resources_quantities(int *ratio, server_t infos);
int *get_remaining_resources(int *ratio, server_t infos);
void put_food_resource(server_t infos, tile **map, int r);
void put_linemate_resource(server_t infos, tile **map, int r);
void put_deraumere_resource(server_t infos, tile **map, int r);
void put_sibur_resource(server_t infos, tile **map, int r);
void put_mendiane_resource(server_t infos, tile **map, int r);
void put_phiras_resource(server_t infos, tile **map, int r);
void put_thystame_resource(server_t infos, tile **map, int r);

// TASK
void add_task(server_t *server, char *cmd, double time, client_t *cli);
void execute_tasks(server_t *server);
void send_task_response(server_t *server, task_t *task, char *cmd);
void forward_command(server_t *server, client_t *client);
void right_command(client_t *client);
void left_command(client_t *client);
void inventory_command(client_t *client);
void look_command(server_t *server, client_t *client);

// CMD
void move_player(player *p, tile **map, int *pos, server_t *s_infos);
int get_case(server_t *server, char dir, int tile, int diff);
int get_nb_tiles_per_level(int level);
int get_first_case_id_per_level(server_t *server, int tile, char dir, int level);
char *get_all_tile_infos(tile *target);
char *get_all_tiles_per_level(server_t *server, client_t *client, int level);

// PLAYER
void generate_player(server_t *server, client_t *cli, int socket, char *team_name);
void generate_gui_player(client_t *cli, int socket);

// DEBUG
void debug_print_map(server_t *s_infos, tile **map);
void debug_print_gui_player(client_t *cli);
void debug_print_player(client_t *cli);
void debug_print_task_queue(server_t *server);

//TIME
double calculate_time_for_task(server_t *server, char *buffer);
