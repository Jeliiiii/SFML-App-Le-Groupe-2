#include "GameManager.hpp"

Input::Input(RenderWindow& window)
{
	shoot = false;
	escape = false;
	mousePosition = Mouse::getPosition(window);
}

void Input::InputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}
}