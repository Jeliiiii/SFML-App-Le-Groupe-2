#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


// Fonction main, point de départ du programme
int main()
{

    // Création de la fenêtre avec taille et titre
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "Mon Titre");

    // Modification du titre de la fenêtre
    window.setTitle("Titre modifié");


    // Fin du programme
    return 0;
}