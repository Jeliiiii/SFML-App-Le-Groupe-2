#include "main.hpp"

Input input;
Clock deltaClock;
float deltaTime = 0; //Variable qui reset la clock à 0 et récupère le temps qui s'est écoulé

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Casse-briques");

    window.setVerticalSyncEnabled(true);

    GameObject rect(100, 100, 200, 200, 45, 50, Color::Red);
	GameObject rect2(200, 200, 100, 100, 45, 50, Color::Blue);
	GameObject rect3(500, 400, 150, 150, 45, 100, Color::Green);
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
        window.draw(*rect3.getShape());
        window.draw(*circ.getShape());
        window.draw(*rect2.getShape());
        window.draw(*rect.getShape());

		circ.Move(deltaTime);
        

		rect.Move(deltaTime);
        rect.CollideWindow();

		rect2.Move(deltaTime);
        rect2.CollideWindow();

		rect3.Move(deltaTime);
        rect3.CollideWindow();

        //if (input.getShoot() == true)
        //{            
        //}
		
        deltaTime = deltaClock.restart().asSeconds();
        window.display();
    }
    return 0;
}