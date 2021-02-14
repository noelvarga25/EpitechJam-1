/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Button
*/

#include <UIObject/Button.hpp>

namespace UIObject {

    /**  Public  **/

    // Construction of Object
    Button::Button() : Core::Object()
    {
    }

    Button::Button(int ID, sf::Texture &m_txtr, sf::Vector2f pos)
    {
        m_id = ID;
        m_sprt.setTexture(m_txtr);
        m_sprt.setPosition(pos);
    }

    Button::~Button()
    {
    }

    // Getter
    int Button::getID() { return m_id; }

    // Gestion of display
    void Button::updateDisplay() {}

    // Gestion of Event
    int Button::updateEvent(sf::RenderWindow &screen, sf::Event event)
    {
        sf::Vector2f mouse_pos = screen.mapPixelToCoords(sf::Mouse::getPosition(screen));
        sf::FloatRect rect = m_sprt.getGlobalBounds();

        if (event.type != sf::Event::MouseButtonPressed) {
            return DEFAULT_OBJECT_ID;
        }
        if (rect.contains(mouse_pos)) {
            return m_id;
        }
        return DEFAULT_OBJECT_ID;
    }

    /**  Private  **/

    // Drawable
    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        target.draw(m_sprt, states);
	}
}