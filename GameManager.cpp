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
		if (event.key.code == Keyboard::Escape)
		{
			window.close();
		}
	}

	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			Vector2i mousePosition = Mouse::getPosition(window);
			Vector2f mousePositionLocal = window.mapPixelToCoords(mousePosition);
			shoot = true;
		}
	}

	if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			shoot = false;
		}
	}
}

bool Input::Shoot()
{
	return shoot;
}

Vector2i Input::getMousePosition()
{
	return mousePosition;
}

Vector2i Input::getMousePositionLocal()
{
	return mousePositionLocal;
}