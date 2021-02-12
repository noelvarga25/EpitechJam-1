/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** the Player class function
*/

#include "Player.hpp"

#define SPEED=10

namespace Game
{

    Player::Player(): Object()
    {

    }

    Player::~Player()
    {

    }

    void Player::setTimeState(TIMESTATE newState)
    {
        this->_state = newState;
    }

    TIMESTATE Player::getTimeState() const
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

}