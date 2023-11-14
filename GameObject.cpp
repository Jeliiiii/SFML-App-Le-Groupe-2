#include <iostream>
#include <cmath>
#include "GameManager.hpp"


GameObject::GameObject(float x, float y, float w, float h, float orientation, float speed, Color color)
{

	position.x = x;
	position.y = y;

	this->w = w;
	this->h = h;
	this->orientation = orientation;
	this->speed = speed;
	this->color = color;

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setPosition(position.x, position.y);
	pShape->setFillColor(color);
	pShape->setOrigin(w / 2.0f, h / 2.0f);
	setRotationAngle(orientation);

};

GameObject::GameObject(float x, float y, float r, float orientation, float speed, Color color)
{

	position.x = x;
	position.y = y;

	this->r = r;
	this->orientation = orientation;
	this->speed = speed;
	this->color = color;

	pShape = new CircleShape(r);
	pShape->setPosition(position.x, position.y);
	pShape->setFillColor(color);
	pShape->setOrigin(w / 2, h / 2);
	setRotationAngle(orientation);

};

Vector2f GameObject::getPosition()
{
	return position;
}

void GameObject::setRotationAngle(float angle)
{
	orientation = angle;
	pShape->setRotation(angle);
	direction.x = sin(orientation * (M_PI / 180));
	direction.y = -1 * cos(orientation * (M_PI / 180));
}

void GameObject::Move(float deltaTime) 
{
	float x = pShape->getPosition().x + direction.x * deltaTime * speed;
	float y = pShape->getPosition().y + direction.y * deltaTime * speed;
	CollideWindow();
	pShape->setPosition(x, y);
}

Shape* GameObject::getShape() 
{
	return pShape;
}

void GameObject::VerticalBounce()
{
	setRotationAngle(-orientation);
	cout << direction.x << ";" << direction.y << endl;
}

void GameObject::HorizontalBounce()
{
	setRotationAngle(180 - orientation);
	cout << direction.x << ";" << direction.y << endl;
}

void GameObject::CollideWindow()
{
	firstCollision = false;
	Vector2f position = pShape->getPosition();
	float halfWidth = w / 2.0f;
	float halfHeight = h / 2.0f;

	if (firstCollision == true) 
	{
		if (position.x - halfWidth <= 0)
		{
			HorizontalBounce();
			direction.x = -direction.x;
			position.x = halfWidth;
			firstCollision = false;
		}

		if (firstCollision == true)
		{
			HorizontalBounce();
			direction.x = -direction.x;
			position.x = halfWidth;
			firstCollision = false;
		}

		else if (position.x + halfWidth >= WIN_WIDTH)
		{
			HorizontalBounce();
			direction.x = -direction.x;
			position.x = WIN_WIDTH - halfWidth;
			firstCollision = false;
		}


		if (position.y - halfHeight <= 0)
		{
			VerticalBounce();
			direction.y = -direction.y;
			position.y = halfHeight;
			firstCollision = false;
		}

		else if (position.y + halfHeight >= WIN_HEIGHT)
		{
			VerticalBounce();
			direction.y = -direction.y;
			position.y = WIN_HEIGHT - halfHeight;
			firstCollision = false;
		}
	}
	
	pShape->setPosition(position);

}