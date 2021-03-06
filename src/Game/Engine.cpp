/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Engine
*/

#include "Game/Engine.hpp"

namespace Game {
    Engine::Engine(Core::Data &data) : m_player(data) {
        m_isload = false;
        m_time = time::Present;
    }

    Engine::~Engine() {}

    void Engine::load(std::string config, Core::Data &data) {
        std::ifstream file(config);
        std::string param;
        std::string arg;

        m_scene.clear();
        if (!file)
            throw std::string("Can't open file: " + config);
        file >> param >> arg;
        if (param != "size:")
            throw std::string("No size specified");
        m_dim = static_cast<sf::Vector2i>(Tool::atovec(arg, 'x'));
        file >> param >> arg;
        if (param != "tile_size:")
            throw std::string("No tile size specified");
        m_tile_dim = static_cast<sf::Vector2i>(Tool::atovec(arg, 'x'));
        if (m_tile_dim.x <= 0 || m_tile_dim.y <= 0)
            throw std::string("Error on the size: " + arg);
        loadScene(file, data);
        loadScene(file, data);
        loadScene(file, data);
        if (m_scene.size() != 3)
            throw std::string("No much scene (need 3 got " + std::to_string(m_scene.size()) + ")");
        m_isload = true;
    }

    void Engine::updateEvent(sf::RenderWindow &screen, sf::Event event) {
        m_player.updateEvent(screen, event);
    }

    void Engine::updateDisplay(sf::View *view) {
        float posx = m_player.getCenterPosition().x;

        if (posx < SIZE_X / 2)
            posx = SIZE_X / 2;
        else if (m_player.getPosition().x > m_tile_dim.x * TILE_SIZE)
            posx = (m_tile_dim.x * TILE_SIZE) - SIZE_X;
        view->setCenter((sf::Vector2f(posx, SIZE_Y / 2)));
        m_player.updatePos(m_scene.at(m_player.getTimeState())->getTile());
    }

    bool Engine::isLoad() const {
        return m_isload;
    }

    void Engine::clear() {
        m_scene.clear();
        m_isload = false;
    }

    void Engine::loadScene(std::ifstream &file, Core::Data &data) {
        std::string param;
        std::string arg;
        std::string sce_name;

        file >> sce_name;
        sce_name.pop_back();
        sce_name.erase(0, 1);
        m_scene.emplace_back(std::make_unique<Scene>(m_dim, m_tile_dim));
        while (!file.eof()) {
            file >> param;
            if (param == "<platform>") {
                m_scene.back()->setTilePlatform(readTile(file, "</platform>"));
                continue;
            } else if (param == "</" + sce_name + ">") {
                break;
            }
            file >> arg;
            if (param == "asset_bg:") {
                m_scene.back()->setTextureBackground(data.getTexture().at(std::atoi(arg.c_str())));
            } else if (param == "asset_plat:") {
                m_scene.back()->setTexturePlatform(data.getTexture().at(std::atoi(arg.c_str())));
            }
        }
        m_scene.back()->init();
    }

    std::vector<std::vector<int>> Engine::readTile(std::ifstream &file, std::string breaker) {
        std::vector<std::vector<int>> tilemap;
        std::string line;
        std::vector<std::string> rsplit;

        std::getline(file, line);
        std::getline(file, line);
        while (line != breaker) {
            std::vector<int> res;

            rsplit = Tool::split(line, ':');
            for (std::string n : rsplit) {
                res.emplace_back(std::atoi(n.c_str()) - 1);
            }
            if (res.size() != m_dim.x) {
                throw std::string("Invalide tile map size");
            }
            tilemap.emplace_back(res);
            std::getline(file, line);
        }
        if (tilemap.size() != m_dim.y)
            throw std::string("Invalide tile map size");
        return tilemap;
    }

    void Engine::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(*m_scene.at(m_player.getTimeState()), states);
        target.draw(m_player);
    }
}