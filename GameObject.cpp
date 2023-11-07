#include "GameObject.hpp"

GameObject::GameObject(float x, float y, float w, float h, Color color) {

	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setPosition(x, y);
	pShape->setFillColor(color);

};

GameObject::GameObject(float x, float y, float r, Color color) {
	
	pShape = new CircleShape(r);
	pShape->setPosition(x, y);
	pShape->setFillColor(color);

}

Shape* GameObject::getShape() {
	return pShape;
}

/*GameObject::

int GameObject::setRotation(float rotationAngle) {
	return rotationAngle;
}
*/
