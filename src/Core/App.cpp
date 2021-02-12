/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** App
*/

#include <Core/App.hpp>

namespace Core {

    /**  Public  **/

    // Construction of Object
    App::App() :
        m_screen(sf::VideoMode(SIZE_X, SIZE_Y), "Monkey Time Warp 3"),
        m_view(sf::Vector2f(SIZE_X / 2, SIZE_Y / 2), sf::Vector2f(SIZE_X * 1.5, SIZE_Y * 1.5)),
        m_data("./bin/data.config"), m_menu()
    {
        std::cout << "[APP]::[constructor]" << std::endl;
        m_screen.setView(m_view);
        m_menu.load("./bin/menu/main.omn", m_data);
    }

    App::~App()
    {
        std::cout << "[APP]::[destructor]" << std::endl;
    }

    // Gestion of Object
    int App::run()
    {
        std::cout << "[APP]::[run] - start -" << std::endl;
        while (m_screen.isOpen()) {
            while (m_screen.pollEvent(m_event)) {
                if (m_event.type == sf::Event::Closed) {
                    m_screen.close();
                }
                this->updateEvent();
            }
            this->updateDisplay();
            this->display();
        }
        std::cout << "[APP]::[run] - end -" << std::endl;
        return 0;
    }

    void App::updateEvent() {
        m_menu.updateEvent(m_screen, m_event);
    }

    void App::updateDisplay() {
        m_menu.updateDisplay();
    }

    void App::display()
    {
        m_screen.clear(sf::Color::White);
        m_screen.draw(m_menu);
        m_screen.display();
    }
}