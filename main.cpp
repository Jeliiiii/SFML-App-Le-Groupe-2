#include "main.hpp"

Input input;

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Titre de la fenêtre");

    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) 
    {
        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        window.clear(Color::Black);

        // C'est ici qu'on dessine les éléments du jeu


        window.display();
    }

    return 0;
}