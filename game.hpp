#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Input
{
	struct Button { bool left, right, space, escape; };

public:
	Input();

	//Prototypes fonctions
	Button GetButton(void) const;
	void InputHandler(Event event, RenderWindow& window);

private:
	Button button;
};
