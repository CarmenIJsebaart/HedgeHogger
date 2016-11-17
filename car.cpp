#include "car.h"

Car::Car()
{
  width = 25;
  length = 50;
  position.x = start_position_x;
  position.y = start_position_y;
  position_x = start_position_x;
  position_y = start_position_y;
  car_shape.setSize(sf::Vector2f(length, width));
  car_shape.setPosition(position);
  car_shape.setFillColor(sf::Color::Yellow);
}

sf::Vector2f Car::getPosition()
{
  return car_shape.getPosition();
}

void Car::setPosition()
{
  car_shape.setPosition(sf::Vector2f(position_x, position_y));
}

sf::RectangleShape Car::getShape()
{
  return car_shape;
}
