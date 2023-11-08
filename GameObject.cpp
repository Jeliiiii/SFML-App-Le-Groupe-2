#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(float x, float y, float w, float h, float speed, Color color) {

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->direction = direction;
	this->speed = speed;
	this->color = color;

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setPosition(x, y);
	pShape->setFillColor(color);

};

GameObject::GameObject(float x, float y, float r, float speed, Color color) {

	this->x = x;
	this->y = y;
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


void GameObject::Move(float deltaTime/*, vector<float> direction*/) {

	x += deltaTime * /*direction **/ speed;
	y += deltaTime * /*direction **/ speed;
	pShape->setPosition(x, y);

}


Shape* GameObject::getShape() {

	return pShape;

}