/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Scene
*/

#include "Game/Scene.hpp"

namespace Game {
    Scene::Scene(sf::Vector2i dim, sf::Vector2i tile_dim) {
        m_dim = dim;
        m_tile_dim = tile_dim;
    }

    Scene::~Scene() {}

    void Scene::setTextureBackground(sf::Texture &txtr) {
        m_sbg.setTexture(txtr);
    }

    void Scene::setTexturePlatform(sf::Texture &txtr) {
        m_splatform.setTexture(txtr);
    }

    void Scene::setTilePlatform(std::vector<std::vector<int>> tile) {
        m_rplatform.create(m_dim.x * TILE_SIZE, m_dim.y * TILE_SIZE);

        m_rplatform.clear(sf::Color(0, 0, 0, 0));
        for (int y = 0; y < m_dim.y; y++) {
            for (int x = 0; x < m_dim.x; x++) {
                if (tile.at(y).at(x) == -1)
                    continue;
                m_splatform.setTextureRect(sf::IntRect(sf::Vector2i((tile.at(y).at(x) % m_tile_dim.x) * TILE_SIZE,
                    (tile.at(y).at(x) / m_tile_dim.y) * TILE_SIZE), sf::Vector2i(TILE_SIZE, TILE_SIZE)));
                m_splatform.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                std::cout << "pos: " << x * TILE_SIZE << " " << y * TILE_SIZE << std::endl;
                m_rplatform.draw(m_splatform);
            }
        }
        m_rplatform.display();
        m_fsplatform.setTexture(m_rplatform.getTexture());
    }

    void Scene::init() {
        m_rdTxtr.create(m_dim.x * TILE_SIZE, m_dim.y * TILE_SIZE);
        m_rdTxtr.clear(sf::Color::Black);
        m_rdTxtr.draw(m_sbg);
        m_rdTxtr.draw(m_fsplatform);
        m_rdTxtr.display();
        m_sprt.setTexture(m_rdTxtr.getTexture());
    }
}