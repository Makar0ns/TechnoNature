#include "SFML/Graphics.hpp"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window Title");
    sf::Texture robot1_texture;
    if (!robot1_texture.loadFromFile("assets/rob2front.png"))
    {
        std::cout << "error";
        return 0;
    }

    sf::Sprite robot1;
    robot1.setTexture(robot1_texture);
    robot1.setPosition(sf::Vector2f(200, 200));
    robot1.scale(sf::Vector2f(2,2));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(robot1);
        window.display();
    }

    return 0;
}