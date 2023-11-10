#include "main.hpp"

Input input;
Clock deltaClock;
float deltaTime = 0; //Variable qui reset la clock � 0 et r�cup�re le temps qui s'est �coul�

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Casse-briques");

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
<<<<<<< HEAD
			if (input.Shoot() == true)
			{
				circ.Move(deltaTime);
			}
            float deltaX = input.getMousePositionLocal().x - circ.getPosition().x;
            float deltaY = input.getMousePositionLocal().y - circ.getPosition().y;

            float angleRadians = atan2(deltaY, deltaX);
            float angleDegrees = angleRadians * (180.0f / 3.14159f);

            circ.setRotation(angleDegrees);
=======
            if (input.Shoot() == true) {
                circ.Move(deltaTime);
            }
>>>>>>> ebdc6becba364579115c1e113ebb1d66e8863c79
        }

        window.clear(Color::Black);

        // C'est ici qu'on dessine les �l�ments du jeu

        window.draw(*rect.getShape());
        //rect.Move(deltaTime);

		window.draw(*rect2.getShape());
		//rect2.Move(deltaTime);

		window.draw(*rect3.getShape());
		//rect3.Move(deltaTime);

        window.draw(*circ.getShape());
<<<<<<< HEAD
=======
        /*if (input.Shoot() == true) {
            circ.Move(deltaTime);
        }*/
>>>>>>> ebdc6becba364579115c1e113ebb1d66e8863c79

		deltaTime = deltaClock.restart().asSeconds();
        window.display();
		
    }

    return 0;
}