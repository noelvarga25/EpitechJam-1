/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Tool
*/

#include "Tool.hpp"

namespace Tool {
    Err::Code validityFilePath(std::string path)
    {
        for (char c : path) {
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
                ('0' <= c && c <= '9') || c == '_' || c == '.' ||
                c == '/' || c == '\\') {
                    continue;
            } else {
                return Err::Code::LINE_ERROR;
            }
        }
        return Err::Code::NONE;
    }

    std::vector<std::string> split(std::string str, char csplit)
    {
        std::string tmp;
        std::vector<std::string> split;

        for (char c : str) {
            if (c == csplit) {
                split.push_back(tmp);
				tmp = "";
            } else {
                tmp += c;
            }
        }
        split.push_back(tmp);
        return split;
    }

    sf::Vector2f atovec(std::string str, char csplit)
    {
        std::vector<std::string> split = Tool::split(str, csplit);
        sf::Vector2f vec;

        if (split.size() != 2) {
            std::cout << "[atovec] Error: to much element" << std::endl;
            return { 0, 0 };
        }
        vec = { static_cast<float>(std::atof(split.at(0).c_str())), static_cast<float>(std::atof(split.at(1).c_str())) };
        return vec;
    }

    bool isNum(std::string str)
    {
        for (auto& c : str) {
            if (c < '0' || c > '9') {
                return false;
            }
        }
        return true;
    }
}