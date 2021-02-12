/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** App
*/

#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <Core/Data.hpp>
#include <UIObject/Menu.hpp>

#define SIZE_X 1920
#define SIZE_Y 1080

namespace Core {
    class App {
        public:
            // Construction of Object
            App();
            ~App();
            // Gestion of Object
            int run();
            void updateEvent();
            void updateDisplay();
            void display();
        private:
            sf::RenderWindow m_screen;
            sf::Event m_event;
            sf::View m_view;
            Core::Data m_data;
            UIObject::Menu m_menu;
    };
}