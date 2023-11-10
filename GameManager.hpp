#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
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
	Vector2i getMousePosition();
	Vector2i getMousePositionLocal();

private:
	bool shoot;
	Vector2i mousePosition;
	Vector2i mousePositionLocal;
};
