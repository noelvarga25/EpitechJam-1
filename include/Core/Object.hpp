/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Oject
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Core/Transformable.hpp"
#include "Tool.hpp"

#define DEFAULT_OBJECT_ID -1

namespace Core {
    class Object : public sf::Drawable, public Core::Transformable {
        public:
            // Constructor
            Object();
            virtual ~Object();

            // UIObject::Transformable
                // Setter
            virtual void setPosition(sf::Vector2f pos);
            virtual void setPosition(float x, float y);
            virtual void setRotation(float rot);
            virtual void rotate(float rot);
            virtual void setScale(sf::Vector2f scale);
            virtual void setScale(float x, float y);
            virtual void scale(sf::Vector2f scale);
            virtual void scale(float x, float y);
            virtual void setOrigin(sf::Vector2f origin);
            virtual void setOrigin(float x, float y);
            virtual void move(sf::Vector2f move);
            virtual void move(float x, float y);

            // setter
            virtual void setTexture(sf::Texture txtr);
            virtual void setTextureRect(sf::IntRect rect);

            // UIObject::Transformable
                // Getter
            virtual sf::Vector2f getPosition();
            virtual sf::Vector2f getScale();
            virtual float getRotation();
            virtual sf::Vector2f getOrigin();

            virtual void updateDisplay();
            virtual int updateEvent(sf::RenderWindow &screen, sf::Event event);
            bool transformableLoad(std::string type, std::string param);
        protected:
            // Drawable
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            sf::Sprite m_sprt;
            sf::RenderTexture m_rdTxtr;
    };
}