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
            void load(std::string config, Core::Data &data);
            int run();
        private:
            void loadScene(std::ifstream &file, Core::Data &data);
            std::vector<std::vector<int>> readTile(std::ifstream &file, std::string breaker);
            std::vector<std::unique_ptr<Scene>> m_scene;
            sf::Vector2i m_dim;
            sf::Vector2i m_tile_dim;
            // player
    };
}