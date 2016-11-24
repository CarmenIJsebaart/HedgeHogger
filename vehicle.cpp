#include "vehicle.h"

Vehicle::Vehicle(const sf::Vector2f &any_position, int length, int width, sf::Color color, float speed)
  : color{color},
    length{length},
    position{any_position},
    speed{speed},
    width{width}
{
}

void Vehicle::drive()
{
  position.x = position.x + speed;
  this->position = position;
}

sf::Vector2f Vehicle::getPosition()
{
  return position;
}

void Vehicle::setPosition(const sf::Vector2f &any_position)
{
  this->position = any_position;
}

sf::RectangleShape Vehicle::getShape()
{
  sf::RectangleShape vehicle_shape;
  vehicle_shape.setSize(sf::Vector2f(length, width));
  vehicle_shape.setPosition(position);
  vehicle_shape.setFillColor(color);
  return vehicle_shape;
}

void Vehicle::set_vehicle_left()
{
  if(position.x >= 600)
  {
    position.x = -length;
    this->position = position;
  }
}
