#include "main.hpp"

Input input;


int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Titre de la fenêtre");

    window.setVerticalSyncEnabled(true);

    GameObject rect(0, 0, 300, 200, Color::Red);
	GameObject rect2(200, 200, 300, 200, Color::Blue);
	GameObject rect3(500, 400, 300, 200, Color::Green);
    GameObject Circ(300, 300, 50, Color::Yellow);


    while (window.isOpen()) 
    {
        Event event;

        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        window.clear(Color::Black);

        // C'est ici qu'on dessine les éléments du jeu
        window.draw(*rect.getShape());
		window.draw(*rect2.getShape());
		window.draw(*rect3.getShape());
        window.draw(*Circ.getShape());
        window.display();
    }

    return 0;
}