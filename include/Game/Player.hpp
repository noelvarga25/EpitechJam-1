/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Player class
*/

#pragma once

#include "Core/Object.hpp"
#include "Game/TimeStamp.hpp"
#define SPEED=10

namespace Game
{
    enum JumpState
    {
        None,
        Jump,
        DoubleJump
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
            int updateEvent(sf::RenderWindow &screen, sf::Event event) override;

        protected:
            time _state;
            JumpState _jump;
            sf::Clock _jumpClock;

    };

}