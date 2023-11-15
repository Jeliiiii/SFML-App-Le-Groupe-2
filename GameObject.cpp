#include <iostream>
#include <cmath>
#include "GameManager.hpp"

GameObject::GameObject(float x, float y, float w, float h, Color color)
{
	position.x = x;
	position.y = y;

	this->w = w;
	this->h = h;
	this->color = color;

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setFillColor(color);
	pShape->setOrigin(w / 2.0f, h / 2.0f);

	setPosition(x, y);
};

GameObject::GameObject(float x, float y, float r, float orientation, float speed, Color color)
{

	position.x = x;
	position.y = y;

	this->r = r;
	this->orientation = orientation;
	this->speed = speed;
	this->color = color;

	w = r * 2;
	h = r * 2;

	pShape = new CircleShape(r);
	pShape->setFillColor(color);
	pShape->setOrigin(r, r);

	hitbox = new RectangleShape(Vector2f(w, h));
	hitbox->setOrigin(w / 2.0f, h / 2.0f);

	setPosition(x, y);

	setRotationAngle(orientation);
};

void GameObject::setPosition(float x, float y)
{

	position.x = x;
	position.y = y;

	pShape->setPosition(position.x, position.y);
	hitbox->setPosition(position.x, position.y);
}

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

	setPosition(x, y);
}

Shape* GameObject::getShape() 
{
	return pShape;
}

void GameObject::VerticalBounce()
{
	direction.y = -direction.y;
	/*setRotationAngle(-orientation);
	cout << direction.x << ";" << direction.y << endl;*/
}

void GameObject::HorizontalBounce()
{
	direction.x = -direction.x;
	/*setRotationAngle(180 - orientation);
	cout << direction.x << ";" << direction.y << endl;*/
}

void GameObject::CheckWindowCollision()
{
	Vector2f position = pShape->getPosition();
	float halfWidth = w / 2.0f;
	float halfHeight = h / 2.0f;

	if (position.x - halfWidth <= 0)
	{
		std::cout << "LEFT" << std::endl;
		HorizontalBounce();
		//direction.x = -direction.x;
		position.x = halfWidth;
	}

	if (position.x + halfWidth >= WIN_WIDTH)
	{
		std::cout << "RIGHT" << std::endl;
		HorizontalBounce();
		//direction.x = -direction.x;
		position.x = WIN_WIDTH - halfWidth;
	}


	if (position.y - halfHeight <= 0)
	{
		std::cout << "TOP" << std::endl;
		VerticalBounce();
		//direction.y = -direction.y;
		position.y = halfHeight;
	}

	//if (position.y + halfHeight >= WIN_HEIGHT)
	//{
	//	std::cout << "BOTTOM" << std::endl;
	//	VerticalBounce();
	//	//direction.x = -direction.x;
	//	position.y = WIN_HEIGHT - halfHeight;
	//}

	setPosition(position.x, position.y);
}

bool GameObject::CheckObjectCollisionVertical(const GameObject* rect1, const GameObject* rect2)
{
	Vector2f position1 = rect1->hitbox->getPosition();
	Vector2f position2 = rect2->pShape->getPosition();

	float h1 = rect1->h;
	float h2 = rect2->h;

	float top1 = position1.y - h1 / 2;
	float bottom1 = position1.y + h1 / 2;

	float top2 = position2.y - h2 / 2;
	float bottom2 = position2.y + h2 / 2;
	
	return (top1 <= bottom2 && bottom1 >= top2);
}

bool GameObject::CheckObjectCollisionHorizontal(const GameObject* rect1, const GameObject* rect2)
{
	Vector2f position1 = rect1->hitbox->getPosition();
	Vector2f position2 = rect2->pShape->getPosition();

	float w1 = rect1->w;
	float w2 = rect2->w;

	float left1 = position1.x - w1 / 2;
	float right1 = position1.x + w1 / 2;

	float left2 = position2.x - w2 / 2;
	float right2 = position2.x + w2 / 2;

	return (left1 <= right2 && right1 >= left2);
}

void GameObject::CheckCollisions(const GameObject& goOther)
{
	bool isCollidingHorizontal = CheckObjectCollisionHorizontal(this, &goOther);
	bool isCollidingVertical = CheckObjectCollisionVertical(this, &goOther);
	if (isCollidingHorizontal == true)
	{
		cout << "hrz" << endl;
		HorizontalBounce();
	}

	if (isCollidingVertical == true)
	{
		cout << "vrt" << endl;
		VerticalBounce();
	}

	hitbox->setPosition(position.x, position.y);

}