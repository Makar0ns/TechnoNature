#include <SFML/Graphics.hpp>
#include <iostream>
const int tile_cnt = 300;
struct Tile
{
    float x;
    float y;
    char status;
    char structure;
};
Tile map[tile_cnt];
void create_map(int numberOfHexagons_horizontal, int numberOfHexagons_vertical)
{
    for (int i = 0; i < tile_cnt; ++i)
        map[i].status = 'w';
    for (int i = 0; i <= 15; ++i)
        for (int j = 4; j <= 9; ++j)
            map[j + i * 17].status = 'g';
    map[4].status = 'w';
    map[6].status = 'w';
    map[8].status = 'f';
    map[68].status = 'w';
    map[70].status = 'w';
    map[103].status = 't';
    map[151].status = 't';
    map[135].status = 'w';
    map[133].status = 'w';
    map[199].status = 'w';
    map[201].status = 'w';
    map[201].status = 'w';
    map[258].status = 'w';
    map[259].status = 'w';
    map[260].status = 'm';

}
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
        for (int j = 0; j <numberOfHexagons_horizontal-1; ++j)
        {
            sign = -1;
            for (int i = 1; i <=numberOfHexagons_vertical; ++i)
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
        startY += 3 * side;
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
        float x_, y_;
        hexagon.setFillColor(sf::Color(128, 128, 128));
        hexagon.setOutlineThickness(2);
        hexagon.setOutlineColor(sf::Color::Blue);
        for (int i = 0; i < tile_cnt; ++i)
            map[i].status = 'w';
        for (int i = 0; i <= 15; ++i)
            for (int j = 4; j <= 9; ++j)
            {
                map[j + i * 17].status = 'g';
                x_ = map[j + i * 17].x;
                y_ = map[j + i * 17].y;
                hexagon.setPosition(x_, y_);
                window.draw(hexagon);
            }
        window.display();
    }
    return 0;
}
