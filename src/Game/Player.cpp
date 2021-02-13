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

    Player::Player(): _jumpClock(), _animClock(), _animRect(0, 32, 32, 32), Object()
    {
        _jump = None;
        _state = Present;
        _spacePressed = false;
        _leftPressed = false;
        _rightPressed = false;
        _playerState = Idle;
    }

    Player::~Player()
    {

    }

    void Player::setTimeState(time newState)
    {
        _state = newState;
    }

    time Player::getTimeState() const
    {
        return _state;
    }

    void Player::moveLeft()
    {
        sf::Time time = _animClock.getElapsedTime();

        if (time.asSeconds() > 0.05) {
            _animRect.left += 32;
            if (_animRect.left >= 608)
                _animRect.left = 0;
            setTextureRect(_animRect);
            _animClock.restart();
        }
        move(-SPEED, 0);
    }

    void Player::moveRight()
    {
        sf::Time time = _animClock.getElapsedTime();

        if (time.asSeconds() > 0.05) {
            _animRect.left += 32;
            if (_animRect.left >= 608)
                _animRect.left = 0;
            setTextureRect(_animRect);
            _animClock.restart();
        }
        move(SPEED, 0);
    }

    float velocity(sf::Time time)
    {
        float v = 0;

        v = -(tan(cos(time.asSeconds() * 6.28))) * 10;
        return v;
    }

    void Player::jump()
    {
        sf::Time time = _jumpClock.getElapsedTime();
        sf::Time timeA = _animClock.getElapsedTime();

        if (time.asSeconds() < 0.5) {
            move(0, velocity(time));
            if (_jump == Jump && timeA.asSeconds() > 0.05) {
                if (_animRect.left < 416)
                    _animRect.left += 32;
                setTextureRect(_animRect);
            } else if (_jump == DoubleJump && timeA.asSeconds() > 0.05) {
                _animRect.left += 32;
                if (_animRect.left >= 512) {
                    _animRect.left = 416;
                    _animRect.top = 64;
                }
                setTextureRect(_animRect);
                _animClock.restart();
            }
        } else {
            if (_jump == Jump) {
                _jump = Fall;
                _animRect.left = 416;
                setTextureRect(_animRect);
            } else if (_jump == DoubleJump) {
                _jump = DoubleFall;
            }
        }
    }

    void Player::fall()
    {
        if (_jump == Fall || _jump == DoubleFall) {
            _animRect.left = 416;
            _animRect.top = 64;
            setTextureRect(_animRect);
        }
        if (getPosition().y < 720) {
            if (_jump == None)
                _jump = Fall;
            move(0, -(tan(cos(0.5 * 6.28))) * 10);
        } else {
            _jump = None;
            setPosition(getPosition().x, 720);
        }
    }

    int Player::updateEvent(sf::RenderWindow &screen, sf::Event event)
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                _animClock.restart();
                _leftPressed = true;
                _animRect.top = 0;
                setScale(-1, 1);
                _playerState = Left;
            }
            if (event.key.code == sf::Keyboard::D) {
                _animClock.restart();
                _rightPressed = true;
                _animRect.top = 0;
                setScale(1, 1);
                _playerState = Right;
            }
            if (event.key.code == sf::Keyboard::Space) {
                if (_jump == None) {
                    _jump = Jump;
                    _animClock.restart();
                    _animRect.top = 64;
                    _jumpClock.restart();
                } else if (_jump == Jump || _jump == Fall) {
                    _jump = DoubleJump;
                    _animClock.restart();
                    _animRect.top = 96;
                    _jumpClock.restart();
                }
                _spacePressed = true;
                _playerState = onJump;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Space) {
               _spacePressed = false;
                if (_jump == None && _leftPressed == false && _rightPressed == false) {
                    _playerState = Idle;
                    _animClock.restart();
                }
            }
            if (event.key.code == sf::Keyboard::Q)
                _leftPressed = false;
            if (event.key.code == sf::Keyboard::D)
                _rightPressed = false;
        }
        return 0;
    }

    void Player::idleAnim()
    {
        sf::Time time = _animClock.getElapsedTime();

        _animRect.top = 32;
        if (time.asSeconds() > 0.15) {
            _animRect.left += 32;
            if (_animRect.left == 672)
                _animRect.left = 0;
            setTextureRect(_animRect);
            _animClock.restart();
        }
    }

    void Player::updatePos()
    {
        if (_jump == None && _leftPressed == false && _rightPressed == false) {
            _playerState = Idle;
            _animRect.left = 0;
            _animRect.top = 32;
        }
        if (_jump == Jump || _jump == DoubleJump)
            jump();
        else
            fall();
        if (_rightPressed == true && _leftPressed == false)
            moveRight();
        if (_leftPressed == true && _rightPressed == false)
            moveLeft();
        if (_playerState == Idle)
            idleAnim();
    }
}