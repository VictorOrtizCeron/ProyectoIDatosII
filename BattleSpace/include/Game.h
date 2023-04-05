#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>


class Game
{
    public:
        Game();
        virtual ~Game();
        void run();
        void update();
        void render();

    protected:

    private:
        sf::RenderWindow* window;
        void initWindow();
};

#endif // GAME_H
