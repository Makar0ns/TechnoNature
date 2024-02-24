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




void create_map(int numberOfHexagons_horizontal, int numberOfHexagons_vertical, Tile map[])
{
    for (int i = 0; i < tile_cnt; ++i)
        map[i].status = 'w';
    for (int i = 0; i <= 15; ++i)
        for (int j = 4; j <= 9; ++j)
            map[j + i * 17].status = 'g';
    map[4].status = 'w';
    map[6].status = 'w';
    map[8].status = 'n';
    map[72].status = 'w';
    map[74].status = 'w';
    map[109].status = 't';
    map[160].status = 't';
    map[140].status = 'w';
    map[142].status = 'w';
    map[208].status = 'w';
    map[210].status = 'w';
    map[275].status = 'm';

    map[19].status = 'a';
    map[20].status = 'g';
    map[105].status = 'g';
    map[121].status = 'g';
    map[120].status = 'g';
    map[137].status = 'g';
    map[155].status = 'g';
    map[156].status = 'g';
    map[241].status = 'g';
    map[257].status = 'a';

    map[27].status = 'g';
    map[78].status = 'g';
    map[129].status = 'g';
    map[146].status = 'g';
    map[163].status = 'g';
    map[214].status = 'g';
    map[241].status = 'g';
    map[265].status = 'g';

    map[28].status = 'g';
    map[113].status = 'g';
    map[164].status = 'g';
    map[249].status = 'g';

    map[46].status = 'g';
    map[131].status = 'g';
    map[148].status = 'e';
    map[165].status = 'g';
    map[250].status = 'g';

    map[47].status = 'g';
    map[81].status = 'g';
    map[115].status = 'g';
    map[166].status = 'g';
    map[200].status = 'g';
    map[234].status = 'g';

    map[65].status = 'g';
    map[82].status = 'g';
    map[116].status = 'g';
    map[184].status = 'g';
    map[218].status = 'g';
    map[235].status = 'g';

    map[49].status = 'g';
    map[83].status = 'g';
    map[100].status = 'g';
    map[185].status = 'g';
    map[202].status = 'g';
    map[236].status = 'g';

    map[67].status = 'g';
    map[84].status = 'p';
    map[220].status = 'p';
    map[237].status = 'g';
}

class Townhall
{
private:
    int side = 35;
    char team;
    bool is_destroyed = false;
    int hp = 1;
    int i = 0;
    int income_aurum = 1;
    int income_etherium = 1;
    int income_pandorium = 1;
    int aurum = 1;
    int etherium = 1;
    int pandorium = 1;
    int cnt_workers = 1;
    sf::CircleShape hexagon;
    sf::Texture texture;

public:
    Townhall(int in_i,char team_in)
    {
        i = in_i;
        team = team_in;
    }
    void draw(sf::RenderWindow& window)
    {
        sf::CircleShape hexagon(side, 6);
        if(team == 'n') 
            texture.loadFromFile("Images\\tower_nature.png");
        else texture.loadFromFile("Images\\tower_robot.png");
        hexagon.setPosition(map[i].x, map[i].y);
        hexagon.setTexture(&texture);
        window.draw(hexagon);
    }
    void change_hp(int damage)
    {
        hp -= damage;
        if (hp < 1) is_destroyed = true;
    }
    void change_income_aurum(int cnt_workers, int cnt_mineschaft_aurum)
    {
        income_aurum = cnt_workers + cnt_mineschaft_aurum * 4;
        aurum += income_aurum;
    }
    void change_income_etherium(int mineschaft_etherium)
    {
        income_etherium += mineschaft_etherium;
        etherium += income_etherium;
    }
    void change_income_pandorium(int mineschaft_pandorium)
    {
        income_pandorium += mineschaft_pandorium;
        pandorium += income_pandorium;
    }

};

int main()
{
    sf::Texture water;
    sf::Texture nature;
    sf::Texture robot;
    sf::Texture pandorium;
    sf::Texture etherium;
    sf::Texture tower_default;
    sf::Texture gray;
    sf::Texture aurum;
    water.loadFromFile("images/water_bg.png");
    nature.loadFromFile("images/nature.png");
    robot.loadFromFile("images/robot.png");
    pandorium.loadFromFile("images/pandorium.png");
    etherium.loadFromFile("images/etherium.png");
    tower_default.loadFromFile("images/tower_default.png");
    gray.loadFromFile("images/Solid_gray.png");
    aurum.loadFromFile("images/gold.png");

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
        int numberOfHexagons_horizontal = 17, numberOfHexagons_vertical = 16;
        int sign = 1, current_i;
        float pos_y, pos_x;
        float startX = 400;
        float startY = 50;
        float horizontalSpacing = side * sqrt(3) / 2;
        float verticalSpacing = 1.5 * side;
        int g;
        create_map(numberOfHexagons_horizontal, numberOfHexagons_vertical, map);
        sf::CircleShape hexagon(side, 6);
        hexagon.setFillColor(sf::Color::White);
        hexagon.setOutlineThickness(2);
        hexagon.setOutlineColor(sf::Color::Black);
        for (int j = 0; j < numberOfHexagons_horizontal - 1; ++j)
        {
            sign = -1;
            for (int i = 1; i <= numberOfHexagons_vertical; ++i)
            {
                pos_y = startY + i * verticalSpacing;
                current_i = i + j * numberOfHexagons_horizontal;
                if (sign == 1)
                {
                    pos_x = startX - horizontalSpacing;
                    hexagon.setPosition(pos_x, pos_y);
                    map[current_i].x = pos_x;
                }
                else
                {
                    hexagon.setPosition(startX, pos_y);
                    map[current_i].x = startX;
                }
                map[current_i].y = pos_y;
                if (map[current_i].status == 'w')
                    hexagon.setTexture(&water);//water закрита зона
                else if (map[current_i].status == 'g')//empty пусті клітинки які можуть бути заповнені
                    hexagon.setTexture(&gray);
                else if (map[current_i].status == 'n')//nature лісові клітинки
                    hexagon.setTexture(&nature);
                else if (map[current_i].status == 't')//tower башні
                    hexagon.setTexture(&tower_default);
                else if (map[current_i].status == 'm')//mechanics 
                    hexagon.setTexture(&robot);
                else if (map[current_i].status == 'a')//aurum
                    hexagon.setTexture(&aurum);
                else if (map[current_i].status == 'e')//etherium
                    hexagon.setTexture(&etherium);
                else if (map[current_i].status == 'p')//pandorium
                    hexagon.setTexture(&pandorium);
                window.draw(hexagon);
                sign = -sign;
                g = current_i;
            }
            startX += side * sqrt(3);

        }

        startY += 3 * side;
        startX -= side * sqrt(3) / 2;
        verticalSpacing = 3 * side;
        for (int k = 0; k < numberOfHexagons_vertical / 2; ++k)
        {
            hexagon.setPosition(startX, startY + k * verticalSpacing);
            map[g].x = startX;
            map[g].y = startY + k * verticalSpacing;
            g++;
            current_i = g;
            if (map[current_i].status == 'w')
                hexagon.setTexture(&water);//water закрита зона
            else if (map[current_i].status == 'g')//empty пусті клітинки які можуть бути заповнені
                hexagon.setTexture(&gray);
            else if (map[current_i].status == 'n')//nature лісові клітинки
                hexagon.setTexture(&nature);
            else if (map[current_i].status == 't')//tower башні
                hexagon.setTexture(&tower_default);
            else if (map[current_i].status == 'm')//mechanics 
                hexagon.setTexture(&robot);
            window.draw(hexagon);
        }
        int aurum = 5;
        Townhall townhall(8, 'n');
        townhall.draw(window);
        Townhall townhall2(274, 'm');
        townhall2.draw(window);

        window.display();
    }
    return 0;
}
