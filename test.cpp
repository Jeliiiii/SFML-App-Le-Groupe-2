//// Move sprite
//playerSprite.move(movement* deltaTime.asSeconds());
//
//// Set bounding box to current position
//boundingBox.setPosition(playerSprite.getPosition());
//
//// Check for collision
//for (auto layer = myLoader.GetLayers().begin(); layer != myLoader.GetLayers().end(); ++layer)
//{
//    if (layer->name == "Collision")
//    {
//        for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
//        {
//            // collision = object->GetAABB().intersects(boundingBox.getGlobalBounds());     
//            if ((boundingBox.getPosition().x + boundingBox.getGlobalBounds().width > object->GetPosition().x && boundingBox.getPosition().x < object->GetPosition().x + object->GetAABB().width) && (boundingBox.getPosition().y + boundingBox.getGlobalBounds().height > object->GetPosition().y && boundingBox.getPosition().y < object->GetPosition().y + object->GetAABB().height))
//            {
//                if ((boundingBox.getPosition().x > object->GetPosition().x) &&
//                    (boundingBox.getPosition().x + boundingBox.getGlobalBounds().width > object->GetPosition().x + object->GetAABB().width))
//                {
//                    boundingBox.setPosition(object->GetPosition().x + object->GetAABB().width, boundingBox.getPosition().y);
//                    std::cout << "Collide on left" << std::endl;
//                }
//                else if ((boundingBox.getPosition().x < object->GetPosition().x) &&
//                    (boundingBox.getPosition().x + boundingBox.getGlobalBounds().width < object->GetPosition().x + object->GetAABB().width))
//                {
//                    boundingBox.setPosition(object->GetPosition().x - boundingBox.getGlobalBounds().width, boundingBox.getPosition().y);
//                    std::cout << "Collide on right" << std::endl;
//                }
//                else if ((boundingBox.getPosition().y > object->GetPosition().y) &&
//                    (boundingBox.getPosition().y + boundingBox.getGlobalBounds().height > object->GetPosition().y + object->GetAABB().height))
//                {
//                    boundingBox.setPosition(boundingBox.getPosition().x, object->GetPosition().y + object->GetAABB().height);
//                    std::cout << "Collide on top" << std::endl;
//                }
//                else if ((boundingBox.getPosition().y < object->GetPosition().y) &&
//                    (boundingBox.getPosition().y + boundingBox.getGlobalBounds().height < object->GetPosition().y + object->GetAABB().height))
//                {
//                    boundingBox.setPosition(boundingBox.getPosition().x, object->GetPosition().y - boundingBox.getGlobalBounds().height);
//                    std::cout << "Collide on bottom" << std::endl;
//                }
//            }
//        }
//    }
//}
//
//playerSprite.setPosition(boundingBox.getPosition());