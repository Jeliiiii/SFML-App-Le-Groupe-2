#pragma once 
#include <SFML/Graphics.hpp> 
#include <iostream>
#include <vector> 

using namespace sf;
using namespace std;

// Définition de la classe GameObject
class GameObject
{

public:

    // Constructeurs de la classe GameObject
    GameObject(float x, float y, float w, float h, float speed, Color color); // Constructeur pour les rectangles
    GameObject(float x, float y, float r, float speed, Color color); // Constructeur pour les cercles

    Shape* getShape(); // Fonction pour obtenir la forme du GameObject
	void Move(float deltaTime, RenderWindow& window);
    void setOrigin(float x, float y);
    Vector2f getPosition();

private:
    Shape* pShape; // Pointeur vers la forme graphique (rectangle, cercle ou autre)
    Color color;
    float w; // Largeur
    float h; // Hauteur
    float r; // Rayon (pour les cercles)
    float rotationAngle; // Angle de rotation (pour certains objets)
	float speed;
    float vx; //Vecteur de vitesse x
    float vy; //Vecteur de vitesse y
    Vector2f position; //Position;
    Vector2i mousePosition;
    Vector2f mousePositionLocal;
    Vector2f direction;
};