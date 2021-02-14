/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Player class
*/

#pragma once

#include "Core/Object.hpp"
#include "Game/TimeStamp.hpp"
#include "Core/Data.hpp"
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
            Player(Core::Data &data);
            virtual ~Player();

            time getTimeState() const;
            sf::Vector2f getCenterPosition() const;
            std::vector<std::vector<int>> getTileAround(std::vector<std::vector<int>> tile, sf::Vector2f pos);

            void setTimeState(time newState);

            void moveLeft(std::vector<std::vector<int>> tile);
            void moveRight(std::vector<std::vector<int>> tile);
            void jump(std::vector<std::vector<int>> tile);
            void fall(std::vector<std::vector<int>> tile);
            int updateEvent(sf::RenderWindow &screen, sf::Event event) override;
            void updatePos(std::vector<std::vector<int>> tile);
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