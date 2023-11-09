#include "GameObject.hpp"
#include <iostream>
#include <cmath>

GameObject::GameObject(float x, float y, float w, float h, float speed, Color color) {

	position.x = x;
	position.y = y;

	this->w = w;
	this->h = h;
	this->speed = speed;
	this->color = color;

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setPosition(x, y);
	pShape->setFillColor(color);

};

GameObject::GameObject(float x, float y, float r, float speed, Color color) {

	position.x = x;
	position.y = y;

	this->r = r;
	this->speed = speed;
	this->color = color;
	
	pShape = new CircleShape(r);
	pShape->setPosition(x, y);
	pShape->setFillColor(color);

}

//void GameObject::Orientation(float x, float y, float w, float h) {
//
//	p
//
//}

Vector2f GameObject::getPosition(){
	return position;
}


void GameObject::Move(float deltaTime, RenderWindow& window) {

	Vector2i mousePosition = Mouse::getPosition(window);
	Vector2f mousePositionLocal = window.mapPixelToCoords(mousePosition);
	Vector2f direction = mousePositionLocal - GameObject::getPosition();

	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (magnitude != 0) {
		direction /= magnitude;
	}

	position.x += deltaTime * speed * direction.x;
	position.y += deltaTime * speed * direction.y;
	pShape->setPosition(position.x, position.y);

}

Shape* GameObject::getShape() {

	return pShape;

}