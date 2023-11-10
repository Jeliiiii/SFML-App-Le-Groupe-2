#include "GameManager.hpp"

Input::Input()
{
	shoot = false;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}

	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Escape){
			window.close();
		}
	}

	if (event.type == Event::MouseButtonPressed) {
		if (event.mouseButton.button == Mouse::Left) {
			shoot = true;
		}
	}
}

bool Input::Shoot(){
	return shoot;
}