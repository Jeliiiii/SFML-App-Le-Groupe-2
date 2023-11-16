#include "main.hpp"

Input input;
Clock deltaClock;
float deltaTime = 0; //Variable qui reset la clock à 0 et récupère le temps qui s'est écoulé

void DrawAll(const vector<GameObject*> objects, RenderWindow& window)
{
    for (int i = 0; i < objects.size(); ++i)
    {
        for (int j = 0; j < objects.size(); ++j)
        {
            window.draw(*objects[i]->getShape());
        }
    }
}

int main()
{
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Casse-briques");

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(120);

    float x = 100;
    float y = 100;

    vector<GameObject*> rects;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            rects.push_back(new GameObject((j+1)*85, (i+1)*85, 70, 50, Color::Red));
        }
    }

    GameObject circ(300, 575, 10, 80, 800, Color::Yellow);

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
        circ.CollisionAll(rects);
		
        //DRAW
        window.clear(Color::Black);

        // C'est ici qu'on dessine les éléments du jeu  
        DrawAll(rects, window);

        window.draw(*circ.getShape());

        window.display();

        //End of loop
        deltaTime = deltaClock.restart().asSeconds();
    }
    return 0;
}