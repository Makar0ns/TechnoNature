#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexagon Example");
    
    sf::Texture grass_texture;
    sf::Texture robot1_texture;
    grass_texture.loadFromFile("assets/robbg.png");
    robot1_texture.loadFromFile("assets/rob2front.png");
    grass_texture.setSmooth(true);
   
    sf::CircleShape hexagon(110.f, 6);
    hexagon.setOutlineColor(sf::Color(51,25,0));
    hexagon.setOutlineThickness(5);
    hexagon.setTexture(&grass_texture);

    sf::Sprite robot1;
    robot1.setTexture(robot1_texture);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(hexagon);
        window.draw(robot1);

        window.display();
    }

    return 0;
}
