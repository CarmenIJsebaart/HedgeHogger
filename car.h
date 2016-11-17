#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>

class Car
{
  sf::RectangleShape car_shape;
  int length;
  int width;
  const int start_position_x = 0;
  const int start_position_y = 500;
  int position_x;
  int position_y;
  sf::Vector2f position;
public:
  Car();
  sf::Vector2f getPosition();
  void setPosition();
  sf::RectangleShape getShape();
};

#endif // CAR_H
