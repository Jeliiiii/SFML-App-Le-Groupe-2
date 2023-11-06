#pragma once
#include <iostream>

using namespace std;

class GameObject
{
	struct Properties { int x, y, width, heigh; string color; };

public:
	GameObject();
	~GameObject();

private:
	int x;
	int y;
	int width;
	int height;
	char color;
	
};

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}