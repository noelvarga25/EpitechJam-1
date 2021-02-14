/*
** EPITECH PROJECT, 2021
** EpitechJam-1
** File description:
** Object
*/

#include "Core/Object.hpp"

namespace Core {
    Object::Object() {
    }

    Object::~Object() {
    }

    // UIObject::Transformable
        // Setter
    void Object::setPosition(sf::Vector2f pos)  { m_sprt.setPosition(pos);  }
    void Object::setPosition(float x, float y)  { m_sprt.setPosition(x, y); }
    void Object::setRotation(float rot)         { m_sprt.setRotation(rot);  }
    void Object::rotate(float rot)              { m_sprt.rotate(rot);       }
    void Object::setScale(sf::Vector2f scale)   { m_sprt.setScale(scale);   }
    void Object::setScale(float x, float y)     { m_sprt.setScale(x, y);    }
    void Object::scale(sf::Vector2f scale)      { m_sprt.scale(scale);      }
    void Object::scale(float x, float y)        { m_sprt.scale(x, y);       }
    void Object::setOrigin(sf::Vector2f origin) { m_sprt.setOrigin(origin); }
    void Object::setOrigin(float x, float y)    { m_sprt.setOrigin(x, y);   }
    void Object::move(sf::Vector2f move)        { m_sprt.move(move);        }
    void Object::move(float x, float y)         { m_sprt.move(x, y);        }

    // sf::Drawable
        // Setter
    void Object::setTexture(sf::Texture &txtr)       { m_sprt.setTexture(txtr);      }
    void Object::setTextureRect(sf::IntRect rect)   { m_sprt.setTextureRect(rect);  }

    // UIObject::Transformable
        // Getter
    sf::Vector2f Object::getPosition()    { return m_sprt.getPosition();    }
    sf::Vector2f Object::getScale()       { return m_sprt.getScale();       }
    float Object::getRotation()           { return m_sprt.getRotation();    }
    sf::Vector2f Object::getOrigin()      { return m_sprt.getOrigin();      }

    void Object::updateDisplay() {}
    int Object::updateEvent(sf::RenderWindow &screen, sf::Event event)  { return DEFAULT_OBJECT_ID; }

    void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(m_sprt, states);
    }

    bool Object::transformableLoad(std::string type, std::string param)
    {
        sf::Vector2f vec = Tool::atovec(param);

        if (type == "pos:") {
            m_sprt.setPosition(vec);
        } else if (type == "rotate:") {
            m_sprt.setRotation(std::atof(param.c_str()));
        } else if (type == "scale:") {
            m_sprt.setScale(vec);
        } else if (type == "origin") {
            m_sprt.setOrigin(vec);
        } else {
            return false;
        }
        return true;
    }

}