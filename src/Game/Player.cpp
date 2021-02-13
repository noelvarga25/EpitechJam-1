/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** the Player class function
*/

#include <cmath>
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

    float velocity(sf::Time time)
    {
        float v = 0;

        v = -(tan(cos(time.asSeconds() * 6.28))) * 10;
        return v;
    }

    void Player::jump()
    {
        sf::Time time = this->_jumpClock.getElapsedTime();

        if (time.asSeconds() < 0.5)
            this->move(0, velocity(time));
        else {
            if (this->_jump == Jump)
                this->_jump = Fall;
            else if (this->_jump == DoubleJump)
                this->_jump = DoubleFall;
        }
    }

    void Player::fall()
    {
        if (this->getPosition().y < 1048) {
            if (this->_jump == None)
                this->_jump = Fall;
            this->move(0, -(tan(cos(0.5 * 6.28))) * 10);
        } else {
            this->_jump = None;
            this->setPosition(this->getPosition().x, 1048);
        }
    }

    int Player::updateEvent(sf::RenderWindow &screen, sf::Event event)
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q)
                this->leftPressed = true;
            if (event.key.code == sf::Keyboard::D)
                this->rightPressed = true;
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Space) {
                if (this->_jump == None) {
                    this->_jump = Jump;
                    this->_jumpClock.restart();
                } else if (this->_jump == Jump || this->_jump == Fall) {
                    this->_jump = DoubleJump;
                    this->_jumpClock.restart();
                }
            }
            if (event.key.code == sf::Keyboard::Q)
                this->leftPressed = false;
            if (event.key.code == sf::Keyboard::D)
                this->rightPressed = false;
        }
        return 0;
    }

    void Player::updatePos()
    {
        if (this->_jump == Jump || this->_jump == DoubleJump)
            this->jump();
        else
            this->fall();
        if (this->rightPressed == true)
            this->moveRight();
        if (this->leftPressed == true)
            this->moveLeft();
    }
}