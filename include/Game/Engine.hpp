/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Engine
*/

#pragma once
#include "Scene.hpp"

namespace Game {
    enum Time {
        Past,
        Present,
        Futur
    };

    class Engine : public sf::Drawable {
        public:
            Engine();
            ~Engine();
            int load(std::string file);
            int run();
        private:
            std::vector<std::unique_ptr<Scene>> m_scene;
            sf::View m_view;
            sf::RenderWindow m_screen;
            // player
    };
}