//#include <cmath>
//
//// ...
//
//int main() {
//    // ...
//
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
//                // Récupérez la position de la souris
//                Vector2i mousePosition = Mouse::getPosition(window);
//
//                // Convertissez la position de la souris en coordonnées locales de la fenêtre
//                Vector2f mousePositionLocal = window.mapPixelToCoords(mousePosition);
//
//                // Calculez la différence entre la position de la souris et la position de votre objet
//                float deltaX = mousePositionLocal.x - ball.getPosition().x;
//                float deltaY = mousePositionLocal.y - ball.getPosition().y;
//
//                // Calculez l'angle en radians
//                float angleRadians = std::atan2(deltaY, deltaX);
//
//                // Convertissez l'angle en degrés si nécessaire
//                float angleDegrees = angleRadians * (180.0f / 3.14159f);
//
//                // Utilisez l'angle pour définir la rotation de votre objet
//                ball.SetRotation(angleDegrees);
//            }
//        }
//
//        // Dessinez et déplacez votre objet
//        window.draw(*ball.getShape());
//        ball.Move(deltaTime);
//
//        // ...
//    }
//
//    return 0;
//}
