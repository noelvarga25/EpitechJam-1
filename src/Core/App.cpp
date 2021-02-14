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
        m_view(sf::Vector2f(SIZE_X / 2, SIZE_Y / 2) , sf::Vector2f(SIZE_X * 1, SIZE_Y * 1)), // Change Zoom here
        m_data("./bin/data.config"), m_menu(), m_engine(m_data)
    {
        std::cout << "[APP]::[constructor]" << std::endl;
        m_music = true;
        m_screen.setView(m_view);
        m_screen.setFramerateLimit(60);
        m_menu.load("./bin/menu/main.omn", m_data);
        m_musicplayer.openFromFile("./bin/asset/MainMenu/title_screen.wav");
    }

    App::~App()
    {
        std::cout << "[APP]::[destructor]" << std::endl;
    }

    // Gestion of Object
    int App::run()
    {
        std::cout << "[APP]::[run] - start -" << std::endl;

        m_musicplayer.play();

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
        switch (m_menu.updateEvent(m_screen, m_event))
        {
        case 0:
            std::cout << "Pressing START button" << std::endl;
            m_menu.clear();
            m_menu.load("./bin/menu/LevelSelector.omn", m_data);
            break;
        case 1:
            std::cout << "Pressing SETTINGS button" << std::endl;
            if (m_music == false) {
                m_menu.clear();
                m_menu.load("./bin/settings/settings_off.omn", m_data);
            } else {
                m_menu.clear();
                m_menu.load("./bin/settings/settings.omn", m_data);
            }
            break;
        case 2:
            std::cout << "Pressing QUIT button" << std::endl;
            m_screen.close();
            break;
        case 3:
            try {
                m_engine.load("./bin/map/1.map", m_data);
            } catch (std::string &e) {
                    std::cout << "An error occured while loading the map: " << e << std::endl;
            }
            break;
        case 4:
            try {
                m_engine.load("./bin/map/1.map", m_data);
            } catch (std::string &e) {
                    std::cout << "An error occured while loading the map: " << e << std::endl;
            }
            break;
        case 5:
            try {
                m_engine.load("./bin/map/1.map", m_data);
            } catch (std::string &e) {
                    std::cout << "An error occured while loading the map: " << e << std::endl;
            }
            break;
        case 6:
            m_menu.clear();
            m_menu.load("./bin/menu/main.omn", m_data);
            break;
        case 20:
            m_music = false;
            m_musicplayer.stop();
            m_menu.clear();
            m_menu.load("./bin/settings/settings_off.omn", m_data);
            break;
        case 21:
            m_music = true;
            m_musicplayer.play();
            m_menu.clear();
            m_menu.load("./bin/settings/settings.omn", m_data);
            break;
        default:
            break;
        }
        if (m_engine.isLoad()) {
            m_engine.updateEvent(m_screen, m_event);
        }
    }

    void App::updateDisplay() {
        m_menu.updateDisplay();
        if (m_engine.isLoad()) {
            m_engine.updateDisplay();
        }
    }

    void App::display()
    {
        m_screen.clear(sf::Color::White);
        m_screen.draw(m_menu);
        if (m_engine.isLoad()) {
            m_screen.draw(m_engine);
        }
        m_screen.display();
    }
}