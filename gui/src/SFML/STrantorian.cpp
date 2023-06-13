/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STrantorian
*/

#include "STrantorian.hpp"

//! Fix animation when a player is ejected and loop eject animation
//* Probably need to get a pointer to cache, instead of a copy so we can update the cache

STrantorian::STrantorian(Trantorian trantorian)
{
    this->createSprite();
    std::cout << "creer Tranto x: " << trantorian.getX() << " y: " << trantorian.getY() << std::endl;
    this->setSpritePosition(sf::Vector2f((-40) + (96 * (trantorian.getX())), (-90) + ((96) * (trantorian.getY()))));
    this->setOrientation(trantorian.getOrientation());
    this->setSpriteScale(sf::Vector2f(3.5, 3.5));
    this->_id = trantorian.getId();
    this->_rect = sf::IntRect(0, 0, 48, 48);
    this->setSpriteRect(this->_rect);
}

STrantorian::~STrantorian()
{
}

void STrantorian::createSprite()
{

    for (int i = 1; i != 9; i++) {
        _textures["down" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["down" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianDownIdle" + std::to_string(i) + ".png");
        _textures["left" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["left" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianLeftIdle" + std::to_string(i) + ".png");
        _textures["up" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["up" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianUpIdle" + std::to_string(i) + ".png");
        _textures["right" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["right" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianRightIdle" + std::to_string(i) + ".png");

        _textures["Wdown" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Wdown" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianDownRun" + std::to_string(i) + ".png");
        _textures["Wleft" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Wleft" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianLeftRun" + std::to_string(i) + ".png");
        _textures["Wup" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Wup" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianUpRun" + std::to_string(i) + ".png");
        _textures["Wright" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Wright" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianRightRun" + std::to_string(i) + ".png");

        _textures["Idown" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Idown" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianDownIncantation" + std::to_string(i) + ".png");
        _textures["Ileft" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Ileft" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianLeftIncantation" + std::to_string(i) + ".png");
        _textures["Iup" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Iup" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianUpIncantation" + std::to_string(i) + ".png");
        _textures["Iright" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Iright" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianRightIncantation" + std::to_string(i) + ".png");

        _textures["Edown" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Edown" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianDownEjection" + std::to_string(i) + ".png");
        _textures["Eleft" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Eleft" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianLeftEjection" + std::to_string(i) + ".png");
        _textures["Eup" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Eup" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianUpEjection" + std::to_string(i) + ".png");
        _textures["Eright" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Eright" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianRightEjection" + std::to_string(i) + ".png");

        _textures["Ddown" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Ddown" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianDownDeath" + std::to_string(i) + ".png");
        _textures["Dleft" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Dleft" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianLeftDeath" + std::to_string(i) + ".png");
        _textures["Dup" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Dup" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianUpDeath" + std::to_string(i) + ".png");
        _textures["Dright" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Dright" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianRightDeath" + std::to_string(i) + ".png");

        _textures["Hdown" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Hdown" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianDownHurt" + std::to_string(i) + ".png");
        _textures["Hleft" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Hleft" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianLeftHurt" + std::to_string(i) + ".png");
        _textures["Hup" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Hup" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianUpHurt" + std::to_string(i) + ".png");
        _textures["Hright" + std::to_string(i)] = std::make_shared<sf::Texture>();
        _textures["Hright" + std::to_string(i)]->loadFromFile("gui/assets/trantorian/TrantorianRightHurt" + std::to_string(i) + ".png");
    }
}

void STrantorian::update(MapT *cache)
{
    if (this->_animation == DEATH) {
        if (this->_rect.left >= 10 * 48) {
            std:: cout << "remove trantorian" << std::endl;
            cache->removeTrantorian(this->_id);
        }
        else
            this->_rect.left += 48;
    } else if (this->_animation == INCANTATION) {
        if (this->_rect.left >= 480)
            this->_rect.left = 48;
        else
            this->_rect.left += 48;
    } else if (this->_animation == EJECTION) {
        if (this->_rect.left >= 6 * 48) {
            cache->setTrantorianEjection(this->_id, false);
            this->_rect.left = 0;
        } else
            this->_rect.left += 48;
    } else {
        if (this->_rect.left >= 204)
            this->_rect.left = 0;
        else
            this->_rect.left += 48;
    }
    this->setSpriteRect(this->_rect);
}

void STrantorian::moveSprite(MapT *cache)
{
    Trantorian t = cache->getTrantorian(this->_id);
    int freq = cache->getFrequency();

    sf::Vector2f targetPosition = sf::Vector2f((-35) + (96 * (t.getX())), (-70) + ((96) * (t.getY())));
    sf::Vector2f currentPosition = this->_sprite.getPosition();

    float distanceThreshold = 1.0f;

    if (t.getOrientation() != 1 && currentPosition.y > targetPosition.y) {
        this->_sprite.setPosition(targetPosition);
    } else if (t.getOrientation() != 4 && currentPosition.x > targetPosition.x) {
        this->_sprite.setPosition(targetPosition);
    } else if (t.getOrientation() != 3 && currentPosition.y < targetPosition.y) {
        this->_sprite.setPosition(targetPosition);
    } else if (t.getOrientation() != 2 && currentPosition.x < targetPosition.x) {
        this->_sprite.setPosition(targetPosition);
    } else {
        sf::Vector2f distance = targetPosition - currentPosition;
        float totalDistance = std::sqrt(distance.x * distance.x + distance.y * distance.y);

        if (totalDistance > distanceThreshold) {
            this->_animation = WALKING;

            float movementSpeed = freq * 1.0f;
            sf::Vector2f direction = movementSpeed / totalDistance * distance;
            sf::Vector2f newPosition = currentPosition + direction;

            this->setSpritePosition(newPosition);
        } else {
            this->_lastAnimation = this->_animation;
            if (t.getDeath() == true) {
                std::cout << "death" << std::endl;
                this->_animation = DEATH;
            } else if (t.getCanEvolve() == true) {
                this->_animation = INCANTATION;
            } else if (t.getEjection() == true) {
                this->_animation = EJECTION;
            } else {
                this->_animation = IDLE;
            }
            if (this->_lastAnimation != this->_animation)
                this->_rect.left = 0;
            this->setSpritePosition(targetPosition);
        }
    }
    this->_level = t.getLevel();
    this->setOrientation(t.getOrientation());
}

void STrantorian::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void STrantorian::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void STrantorian::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void STrantorian::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void STrantorian::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void STrantorian::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
{
    this->_sprite.setTexture(*texture);
}

void STrantorian::setOrientation(int orientation)
{
    if (this->_animation == IDLE) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["up" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["right" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["down" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["left" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == WALKING) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Wup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Wright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Wdown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Wleft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == INCANTATION) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Iup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Iright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Idown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Ileft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == EJECTION) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Eup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Eright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Edown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Eleft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == DEATH) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Dup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Dright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Ddown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Dleft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == HURT) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Hup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Hright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Hdown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Hleft" + std::to_string(this->_level)]);
                break;
        }
    }
}

void STrantorian::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}

sf::Vector2f STrantorian::getSpritePosition()
{
    return this->_sprite.getPosition();
}
