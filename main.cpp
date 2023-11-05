#include "main.hpp"

Input input;

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Titre de la fen�tre");

    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) 
    {
        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        window.clear(Color::Black);

        // C'est ici qu'on dessine les �l�ments du jeu


        window.display();
    }

    return 0;
}