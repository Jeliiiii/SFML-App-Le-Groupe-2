#include "main.hpp"

Input input;
Clock deltaClock;
float deltaTime = 0; //Variable qui reset la clock à 0 et récupère le temps qui s'est écoulé

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Titre de la fenêtre");

    window.setVerticalSyncEnabled(true);

    GameObject rect(100, 100, 300, 200, 50, Color::Red);
	GameObject rect2(200, 200, 300, 100, 50, Color::Blue);
	GameObject rect3(500, 400, 200, 150, 100, Color::Green);
    GameObject circ(300, 300, 50, 50, Color::Yellow);

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
        //rect.Move(deltaTime);

		window.draw(*rect2.getShape());
		//rect2.Move(deltaTime);

		window.draw(*rect3.getShape());
		//rect3.Move(deltaTime);

        window.draw(*circ.getShape());
		circ.Move(deltaTime, directionCirc);

		deltaTime = deltaClock.restart().asSeconds();
        window.display();
		
    }

    return 0;
}