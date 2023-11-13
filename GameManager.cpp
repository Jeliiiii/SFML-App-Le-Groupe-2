#include "GameManager.hpp"

Input::Input()
{
	shoot = false;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
	Vector2i mousePosition = Mouse::getPosition(window);
	Vector2f mousePositionLocal = window.mapPixelToCoords(mousePosition);

	if (event.type == Event::Closed)
	{
		window.close();
	}

	if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
	{
		window.close();
	}

	if ((event.type == Event::MouseButtonPressed) && (event.mouseButton.button == Mouse::Left))
	{
		shoot = true;
	}

	if ((event.type == Event::MouseButtonReleased) && (event.mouseButton.button == Mouse::Left))
	{
		shoot = false;
	}
}

bool Input::getShoot()
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