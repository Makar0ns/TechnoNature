#include <SFML/Graphics.hpp>
#include <iostream>
struct Tile
{
    float x;
    float y;
    char status;
    char structure;
};
Tile map[300];
int main()
{
    int g;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Hexagons");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        int side = 35;
        sf::CircleShape hexagon(side, 6);
        hexagon.setFillColor(sf::Color::Green);
        hexagon.setOutlineThickness(2);
        hexagon.setOutlineColor(sf::Color::Blue);
        int numberOfHexagons_horizontal = 17, numberOfHexagons_vertical = 16;
        int sign = 1;
        float pos_y, pos_x;
        float startX = 400;
        float startY = 50;
        float horizontalSpacing = side * sqrt(3) / 2;
        float verticalSpacing = 1.5 * side;
        for (int j = 0; j < numberOfHexagons_horizontal; ++j)
        {
            sign = -1;
            for (int i = 0; i < numberOfHexagons_vertical; ++i)
            {
                pos_y = startY + i * verticalSpacing;
                if (sign == 1)
                {
                    pos_x = startX - horizontalSpacing;
                    hexagon.setPosition(pos_x, pos_y);
                    map[i+j*numberOfHexagons_horizontal].x = pos_x;
                }
                else
                {
                    hexagon.setPosition(startX, pos_y);
                    map[i + j * numberOfHexagons_horizontal].x = startX;
                }
                map[i + j * numberOfHexagons_horizontal].y = pos_y;
                window.draw(hexagon);
                sign = -sign;
            }
            startX += side * sqrt(3);
        }
        startY += 1.5 * side;
        startX -= side * sqrt(3) / 2;
        verticalSpacing = 3 * side;
        g = numberOfHexagons_horizontal * numberOfHexagons_vertical-1;
        for (int k = 0; k < numberOfHexagons_vertical / 2; ++k)
        {
            hexagon.setPosition(startX, startY + k * verticalSpacing);
            map[g].x = startX;
            map[g].y = startY + k * verticalSpacing;
            g++;
            window.draw(hexagon);
        }
        window.display();
    }
    return 0;
}
