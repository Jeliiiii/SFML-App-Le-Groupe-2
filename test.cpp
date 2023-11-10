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
//                // R�cup�rez la position de la souris
//                Vector2i mousePosition = Mouse::getPosition(window);
//
//                // Convertissez la position de la souris en coordonn�es locales de la fen�tre
//                Vector2f mousePositionLocal = window.mapPixelToCoords(mousePosition);
//
//                // Calculez la diff�rence entre la position de la souris et la position de votre objet
//                float deltaX = mousePositionLocal.x - ball.getPosition().x;
//                float deltaY = mousePositionLocal.y - ball.getPosition().y;
//
//                // Calculez l'angle en radians
//                float angleRadians = std::atan2(deltaY, deltaX);
//
//                // Convertissez l'angle en degr�s si n�cessaire
//                float angleDegrees = angleRadians * (180.0f / 3.14159f);
//
//                // Utilisez l'angle pour d�finir la rotation de votre objet
//                ball.SetRotation(angleDegrees);
//            }
//        }
//
//        // Dessinez et d�placez votre objet
//        window.draw(*ball.getShape());
//        ball.Move(deltaTime);
//
//        // ...
//    }
//
//    return 0;
//}
