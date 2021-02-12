/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Menu
*/

#pragma once
#include <UIObject/Menu.hpp>

namespace UIObject {

    /**  Public  **/

    // Gestion of Object
    template<class T, class... Args>
    void Menu::add(Args&&... args)
    {
        m_widget.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
}