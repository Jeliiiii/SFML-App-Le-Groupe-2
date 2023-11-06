#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Input
{
	bool shoot;
	bool escape;
	Vector2i mousePosition;
	

public:
	Input(RenderWindow& window);

	//Prototypes fonctions
	Mouse GetMouse(Mouse getPosition(const RenderWindow& window));
	void InputHandler(Event event, RenderWindow& window);
	//int Mouse(int x, int y);

private:
	bool shoot;
	bool escape;
	Mouse mouse;
};
