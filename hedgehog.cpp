#include "hedgehog.h"

Hedgehog::Hedgehog(const sf::Vector2f &any_position, float size, sf::Color color)
  : color{color},
    position{any_position},
    size{size}
{
}

Hedgehog create_hedgehog(const int window_height, const int window_width)
{
  const int size = 15;
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
  position = any_position;
}

sf::CircleShape Hedgehog::getShape()
{
  sf::CircleShape hedgehog_shape;
  hedgehog_shape.setRadius(size);
  hedgehog_shape.setPosition(position);
  hedgehog_shape.setFillColor(color);
  return hedgehog_shape;
}

void move(sf::RenderWindow *window, Hedgehog &hedgehog)
{
  if(hedgehog.getPosition().x >= (2 * hedgehog.getSize()))
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      sf::Vector2f hedgehog_position = hedgehog.getPosition();
      //--hedgehog_position.x;
      hedgehog_position.x = hedgehog.getPosition().x - (hedgehog.getSize());
      hedgehog.setPosition(hedgehog_position);
    }
  }
  if(hedgehog.getPosition().x <= (window->getSize().x - (4 * hedgehog.getSize())))
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      sf::Vector2f hedgehog_position = hedgehog.getPosition();
      //++hedgehog_position.x;
      hedgehog_position.x = hedgehog.getPosition().x + (hedgehog.getSize());
      hedgehog.setPosition(hedgehog_position);
    }
  }
  if(hedgehog.getPosition().y >= hedgehog.getSize())
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      sf::Vector2f hedgehog_position = hedgehog.getPosition();
      //--hedgehog_position.y;
      hedgehog_position.y = hedgehog.getPosition().y - (hedgehog.getSize());
      hedgehog.setPosition(hedgehog_position);
    }
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    sf::Vector2f hedgehog_position = hedgehog.getPosition();
    //++hedgehog_position.y;
    hedgehog_position.y = hedgehog.getPosition().y + (hedgehog.getSize());
    hedgehog.setPosition(hedgehog_position);
  }
}
