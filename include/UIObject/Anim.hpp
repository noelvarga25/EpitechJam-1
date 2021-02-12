/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Anim
*/

#pragma once
#include <Core/Object.hpp>

namespace UIObject {
    class Anim : public Core::Object {
        public:
            Anim();
            Anim(sf::Texture &txtr, sf::Vector2u tile_size, unsigned int fps = 1, sf::Vector2u curser = sf::Vector2u(0, 0));
            virtual ~Anim();

            // Setter
            void setTexture(sf::Texture txtr);
            void setTileSize(sf::Vector2u size);
            void setCruser(sf::Vector2i pos);
            void setFps(float fps);

            // Gestion of object
            void start();
            void stop();

            // Core::Object
            void updateDisplay();
            int updateEvent(sf::RenderWindow &screen, sf::Event event);
        protected:
            // Drawable
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            // Gestion of display
            void upSprite();
            sf::Vector2u m_curser;
            sf::Vector2u m_size;
            sf::Vector2u m_tile_size;
            sf::Vector2u m_txtr_size;
            sf::Clock m_clock;
            bool m_start;
            unsigned int m_fps;
    };
}