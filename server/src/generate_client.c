/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** generate_client
*/

#include "../include/server.h"

client_t *generate_client(int socket)
{
    client_t *client = malloc(sizeof(client_t));
    client->socket = socket;
    client->uid = NULL;
    client->buffer = NULL;
    client->team_name = NULL;
    client->player = NULL;
    client->gui_player = NULL;
    return client;
}