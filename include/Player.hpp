/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Player class
*/

#pragma once

namespace Game
{

    enum TIMESTATE {
        PAST,
        PRESENT,
        FUTUR
    };

    class Player: public Object
    {
        public:
            Player();
            virtual ~Player();

            TIMESTATE getTimeState() const;

            void setTimeState(TIMESTATE newState);

            void moveLeft();

        protected:
            TIMESTATE _state;

    };

}