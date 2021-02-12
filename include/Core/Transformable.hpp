/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Transformable
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace Core {
    class Transformable {
        public:
            // Setter
            virtual void setPosition(sf::Vector2f pos) = 0;
            virtual void setPosition(float x, float y) = 0;
            virtual void setRotation(float rot) = 0;
            virtual void rotate(float rot) = 0;
            virtual void setScale(sf::Vector2f scale) = 0;
            virtual void setScale(float x, float y) = 0;
            virtual void scale(sf::Vector2f scale) = 0;
            virtual void scale(float x, float y) = 0;
            virtual void setOrigin(sf::Vector2f origin) = 0;
            virtual void setOrigin(float x, float y) = 0;
            virtual void move(sf::Vector2f move) = 0;
            virtual void move(float x, float y) = 0;

            // Getter
            virtual sf::Vector2f getPosition() = 0;
            virtual sf::Vector2f getScale() = 0;
            virtual float getRotation() = 0;
            virtual sf::Vector2f getOrigin() = 0;
    };
}