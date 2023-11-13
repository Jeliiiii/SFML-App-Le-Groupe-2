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
	pShape->setOrigin(w / 2, h / 2);
	setRotationAngle(orientation);

};

GameObject::GameObject(float x, float y, float r, float speed, Color color)
{

	position.x = x;
	position.y = y;

	this->r = r;
	this->speed = speed;
	this->color = color;

	pShape = new CircleShape(r);
	pShape->setPosition(position.x, position.y);
	pShape->setFillColor(color);
	pShape->setOrigin(w / 2, h / 2);

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
	pShape->setPosition(x, y);
}

Shape* GameObject::getShape() 
{
	return pShape;
}

void GameObject::VerticalBounce()
{
	setRotationAngle(0 - orientation);
}

void GameObject::HorizontalBounce()
{
	setRotationAngle(180 - orientation);
}

void GameObject::CollideWindow()
{

	bool firstCollision = false;
	Vector2f position = pShape->getPosition();

	if (position.x - (w/2) < 0 || position.x + w - (w / 2) > WIN_WIDTH)
	{
		HorizontalBounce();
		position = pShape->getPosition();
	}

	if (position.y - (h/2) < 0 || position.y + h - (h / 2) > WIN_HEIGHT)
	{
		VerticalBounce();
		position = pShape->getPosition();
	}

}