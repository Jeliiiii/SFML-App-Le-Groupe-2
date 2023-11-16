#include "main.hpp"

Input input;
Clock deltaClock;
float deltaTime = 0; //Variable qui reset la clock à 0 et récupère le temps qui s'est écoulé

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Casse-briques");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);

    float x = 300;
    float y = 300;

    vector<GameObject*> rects;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            rects.push_back(new GameObject(x, y, 200, 50, Color::Red));
            x + 50;
            window.draw(rects[i][j]);
        }
        y + 50;
    }

    GameObject circ(300, 300, 10, 80, 800, Color::Yellow);

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
        circ.CheckCollisions(rects);
		
        //DRAW
        window.clear(Color::Black);

        // C'est ici qu'on dessine les éléments du jeu  
        
        window.draw(*circ.getShape());
        window.draw(rects);

        window.display();

        //End of loop
        deltaTime = deltaClock.restart().asSeconds();
    }
    return 0;
}