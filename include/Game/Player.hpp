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

    class Player: public Core::Object
    {
        public:
            Player();
            virtual ~Player();

            time getTimeState() const;

            void setTimeState(time newState);

            void moveLeft();
            void moveRight();

        protected:
            time _state;

    };

}