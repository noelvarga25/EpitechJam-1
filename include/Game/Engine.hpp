/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Engine
*/

#pragma once
#include "Scene.hpp"
#include "Player.hpp"

namespace Game {
    class Engine : public sf::Drawable {
        public:
            Engine(Core::Data &data);
            ~Engine();
            void load(std::string config, Core::Data &data);
            int run();
            void updateEvent(sf::RenderWindow &screen, sf::Event event);
            void updateDisplay();
            bool isLoad() const;
            void clear();
        private:
            void loadScene(std::ifstream &file, Core::Data &data);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            std::vector<std::vector<int>> readTile(std::ifstream &file, std::string breaker);
            std::vector<std::unique_ptr<Scene>> m_scene;
            sf::Vector2i m_dim;
            sf::Vector2i m_tile_dim;
            Game::Player m_player;
            bool m_isload;
            time m_time;
    };
}