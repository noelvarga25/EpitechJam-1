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

    int Engine::load(std::string file) {
        return 0;
    }

    int Engine::run() {
        if (m_scene.size() != 3)
            return 84;
        return 0;
    }
}