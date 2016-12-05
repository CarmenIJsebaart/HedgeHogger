#include "hedgehog.h"

Hedgehog::Hedgehog(const sf::Vector2f &any_position, float size, sf::Color color)
  : color{color},
    position{any_position},
    size{size}
{
}

sf::Vector2f Hedgehog::getPosition() const noexcept
{
  return position;
}

void Hedgehog::setPosition(const sf::Vector2f &any_position)
{
  this->position = any_position;
}

sf::CircleShape Hedgehog::getShape()
{
  sf::CircleShape hedgehog_shape;
  hedgehog_shape.setRadius(size);
  hedgehog_shape.setPosition(position);
  hedgehog_shape.setFillColor(color);
  return hedgehog_shape;
}
