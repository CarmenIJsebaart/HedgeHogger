#include "car.h"

Car::Car(const sf::Vector2f &any_position)
  : length{50},
    width{25},
    position{any_position}
{
}

sf::Vector2f Car::getPosition()
{
  return position;
}

void Car::setPosition(const sf::Vector2f &any_position)
{
  this->position = any_position;
}

sf::RectangleShape Car::getShape()
{
  sf::RectangleShape car_shape;
  car_shape.setSize(sf::Vector2f(length, width));
  car_shape.setPosition(position);
  car_shape.setFillColor(sf::Color::Yellow);
  return car_shape;
}
