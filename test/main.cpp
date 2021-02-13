#include "Game/Player.hpp"

int main()
{
    sf::RenderWindow rw(sf::VideoMode(1920, 1080, 32), "test");
    sf::Event e;
    sf::Texture t;
    Game::Player p;

    t.loadFromFile("test/Player.png");
    p.setTexture(t);
    p.setTextureRect(sf::IntRect(0, 32, 32, 32));
    rw.setFramerateLimit(60);
    rw.setKeyRepeatEnabled(false);
    while (rw.isOpen()) {
        while (rw.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                rw.close();
                p.updateEvent(rw, e);
        }
        p.updatePos();
        rw.clear();
        rw.draw(p);
        rw.display();
    }
    return 0;
}