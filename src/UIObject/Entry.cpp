/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Entry
*/

#include <UIObject/Entry.hpp>

namespace UIObject {

    /**  Public  **/

    // Constructio of Object
    Entry::Entry() : Button() {
        std::cout << "[Entry]::[constructor]" << std::endl;
    }

    Entry::Entry(int id, sf::Texture &txtr, sf::Font &font, std::string def, sf::Vector2f pos) : Button(id, txtr, pos)
    {
        std::cout << "[Entry]::[constructor]" << std::endl;
        sf::Vector2u size = m_sprt.getTexture()->getSize();

        m_txt.setFont(font);
        m_txt.setString(def);
        m_txt.setCharacterSize(14);
        m_def = def;
        m_act = "";
        m_entry_sprt.setTexture(txtr);
        m_rdTxtr.create(size.x, size.y);
        this->upSprite();
        m_focus = true;
        m_msize = -1;
    }

    Entry::~Entry() {
        std::cout << "[Entry]::[destructor]" << std::endl;
    }

    void Entry::setMaxChar(int max)
    {
        if (max < -1)
            std::cout << "[Entry]::[setMaxChar] Warning: no maximum number of char for entry" << std::endl;
        m_msize = max;
    }

    // Getter
    sf::Text& Entry::getText() { return m_txt; };
    std::string Entry::getInput() { return m_act; };

    // Gestion of Event
    int Entry::updateEvent(sf::RenderWindow &screen, sf::Event event)
    {
        sf::FloatRect rect = m_sprt.getGlobalBounds();
        sf::Vector2f mouse_pos = screen.mapPixelToCoords(sf::Mouse::getPosition(screen));

        if (event.type == sf::Event::MouseButtonPressed) {
            if (rect.contains(mouse_pos)) {
                m_focus = true;
                std::cout << "[Event] Entry has focus" << std::endl;
                return m_id;
            }
            m_focus = false;
            return -1;
        } else if (event.type == sf::Event::EventType::TextEntered && m_focus) {
            if ((int)m_act.size() < m_msize || m_msize == -1) {
                if ((event.text.unicode >= 48 && event.text.unicode <= 57) || (event.text.unicode >= 65 && event.text.unicode <= 90) || (event.text.unicode >= 97 && event.text.unicode <= 122) || (event.text.unicode == 95) || (event.text.unicode == 32)) {
                    char char_tmp = static_cast<char>(event.text.unicode);
                    std::cout << "[Event] Entry add > '" << char_tmp << "'" << std::endl;
                    m_act += char_tmp;
                }
            }
            if (event.text.unicode == 8 && m_act.size() != 0) {
                m_act.pop_back();
            } else if (event.text.unicode == 13) {
                std::cout << "[Event] Entry lost focus from terminate entry" << std::endl;
                m_focus = false;
            }
            this->upSprite();
            return m_id;
        }
        return DEFAULT_OBJECT_ID;
    }

    // Gestion of Display
    void Entry::updateDisplay() {}

    /**  Private  **/

    // Update object
    void Entry::upSprite()
    {
        if (m_act == "") {
            m_txt.setString(m_def);
        } else {
            m_txt.setString(m_act);
        }
        m_rdTxtr.clear({ 0, 0, 0, 0 });
        m_rdTxtr.draw(m_entry_sprt);
        m_rdTxtr.draw(m_txt);
        m_rdTxtr.display();
        m_sprt.setTexture(m_rdTxtr.getTexture());
    }

    // Drawable
    void Entry::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_sprt, states);
    }
}