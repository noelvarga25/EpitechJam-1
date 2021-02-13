/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Player class
*/

#pragma once

#include "Core/Object.hpp"
#include "Game/TimeStamp.hpp"
#define SPEED 10

namespace Game
{
    enum JumpState
    {
        None,
        Jump,
        DoubleJump,
        Fall,
        DoubleFall
    };

    enum PlayerState
    {
        Idle,
        Right,
        Left,
        onJump
    };

    class Player: public Core::Object
    {
        public:
            Player();
            virtual ~Player();

            time getTimeState() const;

            void setTimeState(time newState);

            void moveLeft();
            void moveRight();
            void jump();
            void fall();
            int updateEvent(sf::RenderWindow &screen, sf::Event event) override;
            void updatePos();
            void idleAnim();

        protected:
            time _state;
            JumpState _jump;
            PlayerState _playerState;
            sf::Clock _jumpClock;
            sf::Clock _animClock;
            sf::IntRect _animRect;
            bool _rightPressed;
            bool _leftPressed;
            bool _spacePressed;

    };

}