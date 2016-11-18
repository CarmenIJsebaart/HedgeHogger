#include "truck.h"

Truck::Truck(const sf::Vector2f& any_position)
  : length{100},
    width{30},
    position{any_position}
{
}

sf::Vector2f Truck::getPosition()
{
  return position;
}

void Truck::setPosition(const sf::Vector2f& any_position)
{
  this->position = any_position;
}

sf::RectangleShape Truck::getShape()
{
  sf::RectangleShape truck_shape;
  truck_shape.setSize(sf::Vector2f(length, width));
  truck_shape.setPosition(position);
  truck_shape.setFillColor(sf::Color::Blue);
  return truck_shape;
}
