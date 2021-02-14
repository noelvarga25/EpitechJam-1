/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Core/Data.hpp"
#include "Core/Object.hpp"

#define TILE_SIZE 32

namespace Game {
    class Scene : public Core::Object {
        public:
            Scene(sf::Vector2i dim, sf::Vector2i tile_dim);
            ~Scene();
            void setTextureBackground(sf::Texture &txtr);
            void setTexturePlatform(sf::Texture &txtr);
            void setTilePlatform(std::vector<std::vector<int>> tile);
            void init();
            std::vector<std::vector<int>> getTile();
        private:
            sf::Sprite m_sbg;
            std::vector<std::vector<int>> m_platform;
            sf::Sprite m_splatform;
            sf::Sprite m_fsplatform;
            sf::RenderTexture m_rplatform;
            sf::Vector2i m_dim;
            sf::Vector2i m_tile_dim;
    };
}

#endif /* !SCENE_HPP_ */