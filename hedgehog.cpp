#include "hedgehog.h"

Hedgehog::Hedgehog(const sf::Vector2f &any_position, float size, sf::Color color)
  : color{color},
    position{any_position},
    size{size}
{
}

Hedgehog create_hedgehog(const int window_height, const int window_width)
{
  const float size = 15.0;
  Hedgehog hedgehog(sf::Vector2f((window_width / 2) - size,
                                  window_height - (size * 2)), size, sf::Color::Red);

  return hedgehog;
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
