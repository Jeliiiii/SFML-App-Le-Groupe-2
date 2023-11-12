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
	pShape->setRotation(orientation);
	pShape->setFillColor(color);
	pShape->setOrigin(w / 2.0f, h / 2.0f);

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
	pShape->setOrigin(w / 2.0f, h / 2.0f);

};

Vector2f GameObject::getPosition()
{
	return position;
}

void GameObject::setOrigin(float x, float y) 
{
	position.x = x;
	position.y = y;
}


void GameObject::Move(float deltaTime) 
{
	position.x += direction.x * deltaTime * speed;
	position.y += direction.y * deltaTime * speed;
	pShape->setPosition(position.x, position.y);
}

void GameObject::setRotation(float angle)
{
	orientation = angle;
	pShape->setRotation(angle);
	direction.x = std::sin(orientation * (M_PI / 180));
	direction.y = -1 * std::cos(orientation * (M_PI / 180));
}

Shape* GameObject::getShape() 
{
	return pShape;
}