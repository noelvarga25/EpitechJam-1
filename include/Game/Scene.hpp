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

namespace Game {
    class Scene : public Core::Object {
        public:
            Scene(std::vector<std::vector<int>> bg_tile, std::vector<std::vector<int>> plat_tilen, ::Core::Data &data);
            ~Scene();
        private:
            std::vector<std::vector<int>> m_bg;
            std::vector<std::vector<int>> m_platform;
    };
}

#endif /* !SCENE_HPP_ */