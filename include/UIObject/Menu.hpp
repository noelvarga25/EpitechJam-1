/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Menu
*/

#pragma once
#include <fstream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <Core/Object.hpp>
#include <UIObject/Entry.hpp>
#include <UIObject/Anim.hpp>
#include <Core/Data.hpp>
#include <Error.hpp>
#include <sstream>

namespace UIObject {
    class Menu : public Core::Object {
        public:
            // Construction of Object
            Menu();
            virtual ~Menu();

            // Loading of Object
            Err::Code load(std::string file, Core::Data &data);

            // Gestion of Object
            template<class T, class... Args>
            void add(Args&&... args);
            void clear();

            // Core::Object
            void updateDisplay();
            int updateEvent(sf::RenderWindow &screen, sf::Event event);
        private:
            // Loading of Object
            Err::Code createButton(std::ifstream &is, Core::Data &data);
            Err::Code createEntry(std::ifstream &is, Core::Data &data);
            Err::Code createBackground(std::ifstream &is, Core::Data &data);
            Err::Code createAnimation(std::ifstream &is, Core::Data &data);

            // Drawable
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
            std::vector<std::unique_ptr<Core::Object>> m_widget;
            Err::Code m_error;
            sf::Sprite m_background;
            bool m_bgLoad;
    };
}

#include <UIObject/Menu.inl>