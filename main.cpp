#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


// Fonction main, point de d�part du programme
int main()
{

    // Cr�ation de la fen�tre avec taille et titre
    sf::Window window;
    window.create(sf::VideoMode(800, 600), "Mon Titre");

    // Modification du titre de la fen�tre
    window.setTitle("Titre modifi�");


    // Fin du programme
    return 0;
}