#ifndef TRUCK_H
#define TRUCK_H

#include <SFML/Graphics.hpp>

class Truck
{
  sf::RectangleShape truck_shape;
  int length;
  int width;
  const int start_position_x = 0;
  const int start_position_y = 500;
  int position_x;
  int position_y;
  sf::Vector2f position;
public:
  Truck();
  sf::Vector2f getPosition();
  void setPosition();
  sf::RectangleShape getShape();
};

#endif // TRUCK_H
