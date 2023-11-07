#pragma once 
#include <SFML/Graphics.hpp> 
#include <vector> 

using namespace sf;

// Définition de la classe GameObject
class GameObject
{

public:

    // Constructeurs de la classe GameObject
    GameObject(float x, float y, float w, float h, Color color); // Constructeur pour les rectangles
    GameObject(float x, float y, float r, Color color); // Constructeur pour les cercles

    Shape* getShape(); // Fonction pour obtenir la forme du GameObject
    //const Shape& setRotation(float rotationAngle);

private:

    Shape* pShape; // Pointeur vers la forme graphique (rectangle, cercle ou autre)
    float w; // Largeur
    float h; // Hauteur
    float x; // Position X
    float y; // Position Y
    float r; // Rayon (pour les cercles)
    float rotationAngle; // Angle de rotation (pour certains objets)

};