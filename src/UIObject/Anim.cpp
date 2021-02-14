/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Anim
*/

#include <UIObject/Anim.hpp>
#include <iostream>

namespace UIObject {
    Anim::Anim() {
    }

    Anim::Anim(sf::Texture &txtr, sf::Vector2u tile_size, unsigned int fps, sf::Vector2u curser) : Core::Object()
    {
        m_sprt.setTexture(txtr);
        m_tile_size = tile_size;
        m_txtr_size = txtr.getSize();
        if (m_tile_size.x == 0 || m_tile_size.y == 0) {
            m_size = { 0, 0 };
        } else {
            m_size = { m_txtr_size.x / m_tile_size.x + 1, m_txtr_size.y / m_tile_size.y + 1 };
        }
        m_fps = fps;
        m_curser = curser;
        this->upSprite();
    }

    Anim::~Anim() {
    }

    void Anim::setTexture(sf::Texture txtr)
    {
        m_sprt.setTexture(txtr);
        m_txtr_size = txtr.getSize();
        m_size = { m_txtr_size.x / m_tile_size.x, m_txtr_size.y / m_tile_size.y};
        m_curser = { 0, 0 };
        this->upSprite();
    }

    void Anim::setTileSize(sf::Vector2u size)
    {
        m_tile_size = size;
        m_size = { m_txtr_size.x / m_tile_size.x, m_txtr_size.y / m_tile_size.y};
        m_curser = { 0, 0 };
        this->upSprite();
    }

    void Anim::setCruser(sf::Vector2i pos)
    {
        while (pos.y > 0) {
            pos.y -= m_size.y;
        }
        while (pos.y > 0) {
            pos.y -= m_size.y;
        }
        m_curser = { (unsigned int)-pos.y, (unsigned int)-pos.x };
    }

    void Anim::setFps(float fps)
    {
        m_fps = fps;
    }

    void Anim::stop()
    {
        m_start = false;
    }

    void Anim::start()
    {
        m_start = true;
    }

    void Anim::updateDisplay()
    {
        if (m_clock.getElapsedTime().asSeconds() > 1 / m_fps) {
            m_curser.x++;
            if (m_curser.x == m_size.x - 1) {
                m_curser.x = 0;
            }
            m_clock.restart();
            this->upSprite();
        }
    }

    // Gestion of Event
    int Anim::updateEvent(sf::RenderWindow &screen, sf::Event event) { return DEFAULT_OBJECT_ID; }

    void Anim::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_sprt, states);
    }

    void Anim::upSprite()
    {
        m_sprt.setTextureRect(sf::IntRect(sf::Vector2i(m_curser.x * m_tile_size.x, m_curser.y * m_tile_size.x),
            static_cast<sf::Vector2i>(m_tile_size)));
    }
}