/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Button
*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Core/Object.hpp>

namespace UIObject {
    class Button : public Core::Object {
        public:
            // Construction of Object
            Button();
            Button(int ID, sf::Texture &m_txtr, sf::Vector2f pos = { 0, 0 });
            virtual ~Button();

            // Getter
            int getID();

            // Core::Object
            virtual void updateDisplay();
            virtual int updateEvent(sf::RenderWindow &screen, sf::Event event);
        protected:
            // Drawable
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            int m_id;
    };
}