#include "SFML/Graphics.hpp"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window Title");
    sf::VertexArray hexagon(sf::TriangleFan, 7);    
    hexagon[0].position = sf::Vector2f(100.f, 100.f);
    hexagon[1].position = sf::Vector2f(100.f, 140.f);
    hexagon[2].position = sf::Vector2f(134.f, 120.f);
    hexagon[3].position = sf::Vector2f(134.f, 80.f);
    hexagon[4].position = sf::Vector2f(100.f, 60.f);
    hexagon[5].position = sf::Vector2f(66.f, 80.f);
    hexagon[6].position = sf::Vector2f(66.f, 120.f);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(18, 33, 43)); // Color background
        window.draw(hexagon);
        window.display();
    }

    return 0;
}
