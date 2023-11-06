#include "GameManager.hpp"

Input::Input()
{
	button.left = button.right = button.space = button.escape = false;
}

Input::Button Input::GetButton(void) const 
{
	return button;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::Closed)
	{
		window.close();
	}

	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			break;
		case Keyboard::Left:
			button.left = true;
			cout << "Gauche" << endl;
			break;
		case Keyboard::Right:
			button.right = true;
			cout << "Droite" << endl;
			break;
		case Keyboard::Space:
			button.space = true;
			cout << "Espace" << endl;
			break;
		}
	}

	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;
		case Keyboard::Left:
			button.left = false;
			break;
		case Keyboard::Right:
			button.right = false;
			break;
		case Keyboard::Space:
			button.space = false;
			break;
		}
	}
}