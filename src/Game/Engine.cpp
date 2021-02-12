/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Engine
*/

#include "Game/Engine.hpp"

namespace Game {
    Engine::Engine() {}

    Engine::~Engine() {}

    void Engine::load(std::string config, Core::Data &data) {
        std::ifstream file(config);
        std::string param;
        std::string arg;

        if (!file)
            throw std::string("Can't open file: " + config);
        file >> param >> arg;
        if (param != "size:")
            throw std::string("No size specified");
        m_dim = static_cast<sf::Vector2i>(Tool::atovec(arg, 'x'));
        file >> param >> arg;
        if (param != "tile_dim:")
            throw std::string("No tile size specified");
        m_tile_dim = static_cast<sf::Vector2i>(Tool::atovec(arg, 'x'));
        if (m_tile_dim.x <= 0 || m_tile_dim.y <= 0)
            throw std::string("Error on the size: " + arg);
        loadScene(file, data);
        loadScene(file, data);
        loadScene(file, data);
    }

    int Engine::run() {
        if (m_scene.size() != 3)
            return 84;
        return 0;
    }

    void Engine::loadScene(std::ifstream &file, Core::Data &data) {
        std::string param;
        std::string arg;
        std::string sce_name;

        file >> sce_name;
        sce_name.pop_back();
        sce_name.erase(0, 1);
        m_scene.emplace_back(std::make_unique<Scene>(m_dim, m_tile_dim));
        while (file.eof()) {
            file >> param;
            if (param == "<background>") {
                m_scene.back()->setTileBackground(readTile(file, "</background>"));
            } else if (param == "<platform>") {
                m_scene.back()->setTilePlatform(readTile(file, "</platform>"));
            } else if (param != "</" + sce_name + ">") {
                break;
            }
            file >> arg;
            if (param == "asset_bg:") {
                m_scene.back()->setTextureBackground(data.getTexture().at(std::atoi(arg.c_str())));
            } else if (param == "asset_plat:") {
                m_scene.back()->setTexturePlatform(data.getTexture().at(std::atoi(arg.c_str())));
            }
        }
        if (file.eof())
            throw std::string("No break balise for: <" + sce_name + ">");
    }

    std::vector<std::vector<int>> Engine::readTile(std::ifstream &file, std::string breaker) {
        std::vector<std::vector<int>> tilemap;
        std::string line;
        std::vector<std::string> rsplit;

        std::getline(file, line);
        while (line != breaker) {
            std::vector<int> res;
            rsplit = Tool::split(line, ':');
            for (std::string n : rsplit) {
                res.emplace_back(std::atoi(n.c_str()));
            }
            if (res.size() == m_dim.x) {
                throw std::string("Invalide tile map size");
            }
            std::getline(file, line);
        }
        if (tilemap.size() != m_dim.y)
            throw std::string("Invalide tile map size");
        return tilemap;
    }
}