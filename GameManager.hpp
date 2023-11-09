#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Input {
	
public:
	Input();

	//Prototypes fonctions

	void InputHandler(Event event, RenderWindow& window);
	bool Shoot();

private:
	bool shoot;
};
