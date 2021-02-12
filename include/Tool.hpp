/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Tool
*/

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Error.hpp"
#include <stdlib.h>

namespace Tool {
    /*
    **  Checking character to see if the path is good
    **  @path  path to check
    */
    Err::Code validityFilePath(std::string path);
    /*
    **  spliting a string
    **  @str  string to split
    **  @c    split char
    */
    std::vector<std::string> split(std::string str, char csplit);
    /*
    **  convert string to a vector
    **  @str  string to convert
    **  @c    split char
    */
    sf::Vector2f atovec(std::string, char csplit = ';');
    /*
    **  check if the strnig pass is a number
    **  @str  string to check
    */
    bool isNum(std::string str);
}