/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Player class
*/

#pragma once

#define SPEED=10

#include "Core/Object.hpp"

namespace Game
{

    enum TIMESTATE {
        PAST,
        PRESENT,
        FUTUR
    };

    class Player: public Core::Object
    {
        public:
            Player();
            virtual ~Player();

            TIMESTATE getTimeState() const;

            void setTimeState(TIMESTATE newState);

            void moveLeft();
            void moveRight();

        protected:
            TIMESTATE _state;

    };

}