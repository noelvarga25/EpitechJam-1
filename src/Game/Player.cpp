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

    Player::Player(Core::Data &data): _jumpClock(), _animClock(), _animRect(0, 32, 32, 32), Object()
    {
        _jump = None;
        _state = Present;
        _spacePressed = false;
        _leftPressed = false;
        _rightPressed = false;
        _playerState = Idle;
        m_sprt.setTexture(data.getTexture().at(14));
        m_sprt.setTextureRect(sf::IntRect(0, 32, 32, 32));
        setScale(2, 2);
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

    sf::Vector2f Player::getCenterPosition()
    {
         sf::Vector2f pos = this->getPosition();

         pos.x += 32;
         pos.y += 32;
         return pos;
    }

    std::vector<std::vector<int>> Player::getTileAround(std::vector<std::vector<int>> tile, sf::Vector2f pos)
    {
        sf::Vector2f tilePos;
        std::vector<std::vector<int>> tileAround;
        int x = 0;
        int y = 0;

        for (; y != tile.size() - 1; y += 1)
            if (y * 32 >= pos.y - 32 && y * 32 < pos.y)
                break;
        for (; x != tile.at(y).size() - 1; x += 1) {
            if (x * 32 >= pos.x - 32 && x * 32 < pos.x)
                break;
        }
        if (y != 0)
            tileAround.push_back({ tile.at(y - 1).at(x), tile.at(y - 1).at(x + 1)});
        else
            tileAround.push_back({-2, -2});
        if (x != 0) {
            if (x + 2 == tile.at(y).size()) {
                tileAround.push_back({tile.at(y).at(x - 1), -2});
                tileAround.push_back({tile.at(y + 1).at(x - 1), -2});
            } else {
                tileAround.push_back({tile.at(y).at(x - 1), tile.at(y).at(x + 2)});
                tileAround.push_back({tile.at(y + 1).at(x - 1), tile.at(y + 1).at(x + 2)});
            }
        } else {
            tileAround.push_back({-2, tile.at(y).at(x + 2)});
            tileAround.push_back({-2, tile.at(y + 1).at(x + 2)});
        }
        if (y + 2 != tile.size())
            tileAround.push_back({tile.at(y + 2).at(x), tile.at(y + 2).at(x + 1)});
        else
            tileAround.push_back({-2, -2});
        return tileAround;
    }

    void Player::moveLeft(std::vector<std::vector<int>> tile)
    {
        sf::Time time = _animClock.getElapsedTime();

         if (time.asSeconds() > 0.05) {
            _animRect.left += 32;
            if (_animRect.left >= 608)
                _animRect.left = 0;
            setTextureRect(_animRect);
            _animClock.restart();
        }
        if (tile.at(1).at(0) < 0 && tile.at(1).at(0) != -2)
            move(-SPEED, 0);
    }

    void Player::moveRight(std::vector<std::vector<int>> tile)
    {
        sf::Time time = _animClock.getElapsedTime();

        if (time.asSeconds() > 0.05) {
            _animRect.left += 32;
            if (_animRect.left >= 608)
                _animRect.left = 0;
            setTextureRect(_animRect);
            _animClock.restart();
        }
        if (tile.at(1).at(1) < 0 && tile.at(1).at(1) != -2)
                move(SPEED, 0);
    }

    float velocity(sf::Time time)
    {
        float v = 0;

        v = -(tan(cos(time.asSeconds() * 6.28))) * 10;
        return v;
    }

    void Player::jump(std::vector<std::vector<int>> tile)
    {
        sf::Time time = _jumpClock.getElapsedTime();
        sf::Time timeA = _animClock.getElapsedTime();

        if (time.asSeconds() < 0.5) {
            if ((tile.at(0).at(1) < 0 && tile.at(0).at(1) != -2) && (tile.at(0).at(0) < 0 && tile.at(0).at(0) != -2))
                move(0, velocity(time));
            if (_jump == Jump && timeA.asSeconds() > 0.05) {
                if (_animRect.left < 384)
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

    void Player::fall(std::vector<std::vector<int>> tile)
    {
        if (_jump == Fall || _jump == DoubleFall) {
            _animRect.left = 416;
            _animRect.top = 64;
            setTextureRect(_animRect);
        }
        if ((tile.at(3).at(1) < 0 && tile.at(3).at(1) != -2) && (tile.at(3).at(0) < 0 && tile.at(3).at(0) != -2)) {
            if (_jump == None)
                _jump = Fall;
            move(0, -(tan(cos(0.5 * 6.28))) * 10);
        } else {
            _jump = None;
            if ((_leftPressed == true && _rightPressed == false) || (_leftPressed == false && _rightPressed == true))
                _animRect.top = 0;
        }
    }

    int Player::updateEvent(sf::RenderWindow &screen, sf::Event event)
    {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                _animClock.restart();
                _leftPressed = true;
                _animRect.top = 0;
                _animRect.left = 0;
                setScale(-2, 2);
                _playerState = Left;
            }
            if (event.key.code == sf::Keyboard::D) {
                _animClock.restart();
                _rightPressed = true;
                _animRect.top = 0;
                _animRect.left = 0;
                setScale(2, 2);
                _playerState = Right;
            }
            if (event.key.code == sf::Keyboard::Space) {
                if (_jump == None) {
                    _jump = Jump;
                    _animClock.restart();
                    _animRect.top = 64;
                    _animRect.left = 0;
                    _jumpClock.restart();
                } else if (_jump == Jump || _jump == Fall) {
                    _jump = DoubleJump;
                    _animClock.restart();
                    _animRect.top = 96;
                    _animRect.left = 0;
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

    void Player::updatePos(std::vector<std::vector<int>> tile)
    {
        std::vector<std::vector<int>> tileAround = getTileAround(tile, getCenterPosition());

        if (_jump == None && _leftPressed == false && _rightPressed == false) {
            _playerState = Idle;
            _animRect.top = 32;
        }
        if (_jump == Jump || _jump == DoubleJump)
            jump(tileAround);
        else
            fall(tileAround);
        if (_rightPressed == true && _leftPressed == false)
            moveRight(tileAround);
        if (_leftPressed == true && _rightPressed == false)
            moveLeft(tileAround);
        if (_playerState == Idle)
            idleAnim();
    }
}