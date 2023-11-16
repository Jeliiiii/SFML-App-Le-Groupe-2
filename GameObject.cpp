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

	pShape->setPosition(x, y);
};

GameObject::GameObject(float x, float y, float r, float orientation, float speed, Color color)
{

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

	setPositionShape(x, y);

	setRotationAngle(orientation);
};

void GameObject::setPositionShape(float x, float y)
{
	position.x = x;
	position.y = y;

	pShape->setPosition(x, y);
	hitbox->setPosition(x, y);
}

Vector2f GameObject::getPosition()
{
	return position;
}

Shape* GameObject::getHitbox()
{
	return this->hitbox;
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

	setPositionShape(x, y);
}

Shape* GameObject::getShape() 
{
	return pShape;
}

void GameObject::VerticalBounce()
{
	direction.y = -direction.y;
}

void GameObject::HorizontalBounce()
{
	direction.x = -direction.x;
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
		position.x = halfWidth;
	}

	if (position.x + halfWidth >= WIN_WIDTH)
	{
		std::cout << "RIGHT" << std::endl;
		HorizontalBounce();
		position.x = WIN_WIDTH - halfWidth;
	}


	if (position.y - halfHeight <= 0)
	{
		std::cout << "TOP" << std::endl;
		VerticalBounce();
		position.y = halfHeight;
	}

	if (position.y + halfHeight >= WIN_HEIGHT)
	{
		std::cout << "BOTTOM" << std::endl;
		VerticalBounce();
		position.y = WIN_HEIGHT - halfHeight;
	}

	setPositionShape(position.x, position.y);
}

bool GameObject::CheckObjectCollision(const GameObject* obj1, const GameObject* obj2)
{
	Vector2f position1 = obj1->hitbox->getPosition();
	Vector2f position2 = obj2->pShape->getPosition();


	float w1 = obj1->w;
	float w2 = obj2->w;

	float left1 = position1.x - w1 / 2.0f;
	float right1 = position1.x + w1 / 2.0f;

	float left2 = position2.x - w2 / 2.0f;
	float right2 = position2.x + w2 / 2.0f;

	float h1 = obj1->h;
	float h2 = obj2->h;

	float top1 = position1.y - h1 / 2.0f;
	float bottom1 = position1.y + h1 / 2.0f;

	float top2 = position2.y - h2 / 2.0f;
	float bottom2 = position2.y + h2 / 2.0f;

	bool collidesX = (left1 <= right2 && right1 >= left2);
	bool collidesY = (top1 <= bottom2 && bottom1 >= top2);


	if (collidesX)
	{
		HorizontalBounce();
		cout << "oui";
		float overlapX = min(right1 - left2, right2 - left1);
		if (position1.x < position2.x)
		{
			position1.x -= overlapX / 2.0f;
		}
		else
		{
			position1.x += overlapX / 2.0f;
		}
	}


	if (collidesY)
	{
		VerticalBounce();
		cout << "non";
		float overlapY = min(bottom1 - top2, bottom2 - top1);
		if (position1.y < position2.y) 
		{
			position1.y -= overlapY / 2.0f;
		}
			
		else 
		{
			position1.y += overlapY / 2.0f;
		}
	}

	return collidesX || collidesY;
}

void GameObject::CheckCollisions(const GameObject& goOther)
{
	CheckObjectCollision(this, &goOther);
	setPositionShape(position.x, position.y);
}