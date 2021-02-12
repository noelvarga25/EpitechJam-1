/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** the Player class function
*/

#include "Game/Player.hpp"

namespace Game
{

    Player::Player(): _jumpClock(), Object()
    {
        _jump = None;
        _state = Present;
    }

    Player::~Player()
    {

    }

    void Player::setTimeState(time newState)
    {
        this->_state = newState;
    }

    time Player::getTimeState() const
    {
        return this->_state;
    }

    void Player::moveLeft()
    {
        this->move(-SPEED, 0);
    }

    void Player::moveRight()
    {
        this->move(SPEED, 0);
    }

    void Player::jump()
    {
        this->move(0, -SPEED);
    }

    int Player::updateEvent(sf::RenderWindow &screen, sf::Event event) override
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.type.key == sf::Keyboard::Q)
                this->moveLeft();
            if (event.type.key == sf::Keyboard::D)
                this->moveRight();
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.type.key == sf::Keyboard::Space) {
                if (this->_jump == None)
                    this->_jump = Jump;
                else if (this->_jump == Jump)
                    this->_jump = DoubleJump;
                else
                    this->_jump = None;
                this->_jumpClock.restart();
            }
        }
        if (this->_jump != None)
            this->jump();
        return 0;
    }

}