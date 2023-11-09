#include "GameManager.hpp"

Input::Input()
{
	shoot = false;
	escape = false;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}

	if (event.type == Mouse::Left)
	{
		shoot = true;
	}

	Mouse::getPosition();
}