#include "main.hpp"

Input input;
Clock deltaClock;
float deltaTime = 0; //Variable qui reset la clock à 0 et récupère le temps qui s'est écoulé

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Casse-briques");

    window.setVerticalSyncEnabled(true);

    GameObject rect(200, 200, 50, 50, Color::Red);
    GameObject circ(300, 300, 10, 80, 300, Color::Yellow);

    Event event;
    while (window.isOpen()) 
    {
        //EVENT
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        //UPDATE
		circ.Move(deltaTime);  
        circ.CheckWindowCollision();
        circ.CheckCollisions(rect);
		
        //DRAW
        window.clear(Color::Black);

        // C'est ici qu'on dessine les éléments du jeu   
        window.draw(*circ.getShape());
        window.draw(*rect.getShape());

        window.display();

        //End of loop
        deltaTime = deltaClock.restart().asSeconds();
    }
    return 0;
}