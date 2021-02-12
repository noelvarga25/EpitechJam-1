/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Data
*/

#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Error.hpp"
#include "Tool.hpp"

namespace Core {
    class Data {
        public:
            // Construction of Object
            Data(std::string config_file = "./bin/data/data.conf");
            virtual ~Data();

            // Loading of Object
            Err::Code load(std::string config_file);
            Err::Code addLoad(std::string config_file);

            // Gestion of Object
            void clear();

            // Getter of Object
            std::vector<sf::Texture> &getTexture();
            std::vector<sf::Font> &getFont();
        private:
            // Loading of Object
            Err::Code loadImg(std::ifstream &is, std::string refDir);
            Err::Code loadFont(std::ifstream &is, std::string refDir);
            std::vector<sf::Texture> m_txtr;
            std::vector<sf::Font> m_font;
            Err::Code m_error;
    };
}