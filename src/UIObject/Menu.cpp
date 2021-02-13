/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Menu
*/

#include <UIObject/Menu.hpp>

namespace UIObject {

    /**  Public  **/

    // Construction of Object
	Menu::Menu() : Core::Object()
    {
        std::cout << "[Menu]::[constructor]" << std::endl;
        m_error = Err::Code::NONE;
        m_bgLoad = false;
    }

    Menu::~Menu()
    {
        std::cout << "[Menu]::[destructor]" << std::endl;
    }

    // Loading of Object
    Err::Code Menu::load(std::string file, Core::Data &data)
    {
        std::cout << "[MENU]::[load] - start -" << std::endl;
        std::string ext = file;
        std::string line;
        std::ifstream is;

        ext.erase(0, ext.size() - 4);
        if (ext != ".omn") {
            std::cerr << "[MENU]::[load] Error: wrong extenstion" << std::endl;
            m_error = Err::Code::WRONG_EXT;
            return m_error;
        }
        is.open(file);
        if (!is.is_open()) {
            std::cerr << "[MENU]::[load] Error: invalid file" << std::endl;
            m_error = Err::Code::INVALID_FILE;
            return m_error;
        }
        is >> line;
        while (!is.eof()) {
            std::cout << "[MENU]::[load] read > " << line << std::endl;
            if (line == "<Button>") {
                m_error = this->createButton(is, data);
            } else if (line == "<Background>") {
                m_error = this->createBackground(is, data);
            } else if (line == "<Entry>") {
                m_error = this->createEntry(is, data);
            } else if (line == "<Anim>") {
                m_error = this->createAnimation(is, data);
            } else {
                m_error = Err::Code::LINE_ERROR;
                std::cerr << "[MENU]::[load] Error: line formating" << std::endl;
            }
            if (m_error != Err::Code::NONE) {
                is.close();
                std::cerr << "[MENU]::[load] - End from error -" << std::endl;
                return m_error;
            }
            is >> line;
        }
        is.close();
        m_error = Err::Code::NONE;
        std::cout << "[MENU]::[load] - end -" << std::endl;
        return m_error;
    }

    // Gestion of Object
    void Menu::clear()
    {
        m_widget.clear();
    }

    // Gestion of Display
    void Menu::updateDisplay()
    {
        for (auto& widget : m_widget) {
            widget->updateDisplay();
        }
    }

    // Gestion of Event
    int Menu::updateEvent(sf::RenderWindow &screen, sf::Event event)
    {
        for (auto& widget : m_widget) {
            if (widget->updateEvent(screen, event) != -1)
                return widget->updateEvent(screen, event);
        }
        return DEFAULT_OBJECT_ID;
    }

    /**  private  **/

    // Loading of Object
    Err::Code Menu::createButton(std::ifstream &is, Core::Data &data)
    {
        std::string type;
        std::string param;
        bool txtr_build = false;
        bool id_build = false;
        bool gen_build = false;
        int id_txtr;
        int id;

        is >> type >> param;
        while (type != "</Button>") {
            std::cout << "<private> [createButton] read > " << type << " " << param << std::endl;
            if (type == "txtr:") {
                id_txtr = std::atoi(param.c_str());
                if (id_txtr < 0 || (int)data.getTexture().size() < id_txtr) {
                    std::cout << "<private> [createButton] Error: id texture overflow" << std::endl;
                    return Err::Code::ID_TXTR_OVERFLOW;
                }
                txtr_build = true;
            } else if (type == "id:") {
                id = std::atoi(param.c_str());
                id_build = true;
            } else if (!txtr_build || !id_build) {
                std::cerr << "<private> [createButton] Error: the button isn't initialised" << std::endl;
                return Err::Code::NOT_INIT_VAR;
            } else if (!m_widget.back()->transformableLoad(type, param)) {
                if (gen_build) {
                    m_widget.pop_back();
                }
                std::cerr << "<private> [createButton] Error: line formating" << std::endl;
                return Err::Code::LINE_ERROR;
            }
            if (!gen_build && txtr_build && id_build) {
                this->add<UIObject::Button>(id, data.getTexture().at(id_txtr));
                gen_build = true;
            }
            is >> type;
            if (type != "</Button>") {
                is >> param;
            }
        }
        std::cout << "<private> [createButton] - end -" << std::endl;
        return Err::Code::NONE;
    }

    Err::Code Menu::createEntry(std::ifstream &is, Core::Data &data)
    {
        std::string type;
        std::string param;
        std::string def;
        bool txtr_build = false;
        bool font_build = false;
        bool id_build = false;
        bool def_build = false;
        bool gen_build = false;
        int id_txtr;
        int id_font;
        int id;

        is >> type >> param;
        while (type != "</Entry>") {
            std::cout << "<private> [createEntry] read > " << type << " " << param << std::endl;
            if (type == "txtr:") {
                id_txtr = std::atoi(param.c_str());
                if (id_txtr < 0 || (int)data.getTexture().size() < id_txtr) {
                    std::cerr << "<private> [createEntry] Error: id texture overflow" << std::endl;
                    return Err::Code::ID_TXTR_OVERFLOW;
                }
                txtr_build = true;
            } else if (type == "font:") {
                id_font = std::atoi(param.c_str());
                if (id_font < 0 || (int)data.getFont().size() < id_font) {
                    std::cerr << "<private> [createEntry] Error: id texture overflow" << std::endl;
                    return Err::Code::ID_FONT_OVERFLOW;
                }
                font_build = true;
            } else if (type == "id:") {
                id = std::atoi(param.c_str());
                id_build = true;
            } else if (type == "text:") {
                param.erase(0, 1);
                param.erase(param.size() - 1);
                def = param;
                def_build = true;
            } else if (!gen_build) {
                std::cerr << "<private> [createEntry] Error: the button isn't initialised" << std::endl;
                return Err::Code::NOT_INIT_VAR;
            } else if (!m_widget.back()->transformableLoad(type, param)) {
                if (gen_build) {
                    m_widget.pop_back();
                }
                std::cerr << "<private> [createEntry] Error: line formating" << std::endl;
                return Err::Code::LINE_ERROR;
            }
            if (!gen_build && txtr_build && id_build && font_build && def_build) {
                this->add<UIObject::Entry>(id, data.getTexture().at(id_txtr), data.getFont().at(id_font), def);
                gen_build = true;
            }
            is >> type;
            if (type != "</Entry>") {
                is >> param;
            }
        }
        std::cout << "<private> [createEntry] - end -" << std::endl;
        return Err::Code::NONE;
    }

    Err::Code Menu::createBackground(std::ifstream &is, Core::Data &data)
    {
        std::cout << "<private> [createBackground] - start -" << std::endl;
        std::string type;
        std::string param;
        int id;
        sf::Vector2f vec;

        is >> type >> param;
        while (type != "</Background>") {
            std::cout << "<private> [createBackground] read > " << type << " " << param << std::endl;
            vec = Tool::atovec(param);
            if (type == "txtr:") {
                id = std::atoi(param.c_str());
                if (id < 0 || (int)data.getTexture().size() < id) {
                    std::cerr << "<private> [createBackground] Error: id texture overflow" << std::endl;
                    return Err::Code::ID_TXTR_OVERFLOW;
                }
                m_background.setTexture(data.getTexture().at(id));
                m_bgLoad = true;
            } else if (type == "pos:") {
                m_sprt.setPosition(vec);
            } else if (type == "rotate:") {
                m_sprt.setRotation(std::atof(param.c_str()));
            } else if (type == "scale:") {
                m_sprt.setScale(vec);
            } else if (type == "origin") {
                m_sprt.setOrigin(vec);
            } else {
                std::cerr << "<private> [createBackground] Error: line formating" << std::endl;
                return Err::Code::LINE_ERROR;
            }
            is >> type;
            if (type != "</Background>") {
                is >> param;
            }
        }
        std::cout << "<private> [createBackground] - end -" << std::endl;
        return Err::Code::NONE;
    }

    Err::Code Menu::createAnimation(std::ifstream &is, Core::Data &data)
    {
        std::cout << "<private> [createAnimation] - start -" << std::endl;
        std::string type;
        std::string param;
        int id;
        unsigned int fps;
        bool build = false;
        bool build_ts = false;
        bool build_txtr = false;
        bool build_fps = false;
        sf::Vector2f vec;

        is >> type >> param;
        while (type != "</Anim>") {
            std::cout << "<private> [createAnimation] read > " << type << " " << param << std::endl;
            if (type == "txtr:") {
                id = std::atoi(param.c_str());
                if (id < 0 || (int)data.getTexture().size() < id) {
                    std::cerr << "<private> [createAnimation] Error: id texture overflow" << std::endl;
                    return Err::Code::ID_TXTR_OVERFLOW;
                }
                build_txtr = true;
            } else if (type == "tile_size:") {
                vec = Tool::atovec(param);
                build_ts = true;
            } else if (type == "fps:") {
                fps = static_cast<unsigned int>(std::atoi(param.c_str()));
                build_fps = true;
            } else if (!build) {
                std::cerr << "<private> [createAnimation] Error: the button isn't initialised" << std::endl;
                return Err::Code::NOT_INIT_VAR;
            } else if (!m_widget.back()->transformableLoad(type, param)) {
                if (build) {
                    m_widget.pop_back();
                }
                std::cerr << "<private> [createAnimation] Error: line formating" << std::endl;
                return Err::Code::LINE_ERROR;
            }
            if (!build && build_ts && build_txtr && build_fps) {
                this->add<UIObject::Anim>(data.getTexture().at(id), sf::Vector2u((unsigned int)vec.x, (unsigned int)vec.y), fps);
                build = true;
            }
            is >> type;
            if (type != "</Anim>") {
                is >> param;
            }
        }
        std::cout << "<private> [createAnimation] - end -" << std::endl;
        return Err::Code::NONE;
    }

	void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        if (m_error != Err::Code::NONE) {
            return;
        }
        target.draw(m_background, states);
        for (auto& widget : m_widget) {
            target.draw(*widget, states);
        }
    }
}