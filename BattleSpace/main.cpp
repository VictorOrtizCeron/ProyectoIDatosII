#include <SFML/Graphics.hpp>
#include <stdio.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");


    sf::Texture mainShiptexture;
    if (!mainShiptexture.loadFromFile("MainShip.png"))
    {

        return 0;
    }


    sf::Sprite mainShip;
    mainShip.setTexture(mainShiptexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(mainShip);
        window.display();
    }


    return 0;
}

