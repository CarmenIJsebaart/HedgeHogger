#include "truck.h"

Truck::Truck()
{
  width = 30;
  length = 100;
  position.x = start_position_x;
  position.y = start_position_y;
  position_x = start_position_x;
  position_y = start_position_y;
  truck_shape.setSize(sf::Vector2f(length, width));
  truck_shape.setPosition(position);
  truck_shape.setFillColor(sf::Color::Blue);
}

sf::Vector2f Truck::getPosition()
{
  return truck_shape.getPosition();
}

void Truck::setPosition()
{
  truck_shape.setPosition(sf::Vector2f(position_x, position_y));
}

sf::RectangleShape Truck::getShape()
{
  return truck_shape;
}
