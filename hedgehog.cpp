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

void move(sf::RenderWindow * window, Hedgehog &hedgehog, std::vector<Obstacle> obstacles)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    if(hedgehog.getPosition().x >= hedgehog.getSize())
    {
      if(is_touching_obstacle_right(obstacles, hedgehog, hedgehog.getSize()) == false)
      {
        sf::Vector2f hedgehog_position = hedgehog.getPosition();
        //--hedgehog_position.x;
        hedgehog_position.x = hedgehog.getPosition().x - (hedgehog.getSize());
        hedgehog.setPosition(hedgehog_position);
      }
    }
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    if(hedgehog.getPosition().x <= (window->getSize().x - (3 * hedgehog.getSize())))
    {
      if(is_touching_obstacle_left(obstacles, hedgehog, hedgehog.getSize()) == false)
      {
        sf::Vector2f hedgehog_position = hedgehog.getPosition();
        //++hedgehog_position.x;
        hedgehog_position.x = hedgehog.getPosition().x + (hedgehog.getSize());
        hedgehog.setPosition(hedgehog_position);
      }
    }
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    if(hedgehog.getPosition().y >= hedgehog.getSize())
    {
      if(is_touching_obstacle_bottom(obstacles, hedgehog, hedgehog.getSize()) == false)
      {
        sf::Vector2f hedgehog_position = hedgehog.getPosition();
        //--hedgehog_position.y;
        hedgehog_position.y = hedgehog.getPosition().y - (hedgehog.getSize());
        hedgehog.setPosition(hedgehog_position);
      }
    }
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    if(hedgehog.getPosition().y + (2 * hedgehog.getSize()) < window->getSize().y)
    {
      if(is_touching_obstacle_top(obstacles, hedgehog, hedgehog.getSize()) == false)
      {
        sf::Vector2f hedgehog_position = hedgehog.getPosition();
        //++hedgehog_position.y;
        hedgehog_position.y = hedgehog.getPosition().y + (hedgehog.getSize());
        hedgehog.setPosition(hedgehog_position);
      }
    }
  }
}

bool is_touching_obstacle_bottom(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    int y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
    int y_min_hedgehog = hedgehog.getPosition().y;

    int x_min_obstacle = obstacle.getPosition().x;
    int x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
    int x_min_hedgehog = hedgehog.getPosition().x;

    if(y_min_hedgehog == y_max_obstacle &&
       x_min_hedgehog > (x_min_obstacle - (2 * hedgehog_size)) &&
       x_min_hedgehog < (x_max_obstacle))
    {
      return true;
    }
  }
    return false;
}

bool is_touching_obstacle_left(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    int y_min_obstacle = obstacle.getPosition().y;
    int y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
    int y_min_hedgehog = hedgehog.getPosition().y;

    int x_min_obstacle = obstacle.getPosition().x;
    int x_max_hedgehog = hedgehog.getPosition().x + (2 * hedgehog.getSize());

    if(x_max_hedgehog == x_min_obstacle &&
       y_min_hedgehog > (y_min_obstacle - (2 * hedgehog_size)) &&
       y_min_hedgehog < (y_max_obstacle))
    {
      return true;
    }
  }
    return false;
}

bool is_touching_obstacle_right(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    int y_min_obstacle = obstacle.getPosition().y;
    int y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
    int y_min_hedgehog = hedgehog.getPosition().y;

    int x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
    int x_min_hedgehog = hedgehog.getPosition().x;

    if(x_min_hedgehog == x_max_obstacle &&
       y_min_hedgehog > (y_min_obstacle - (2 * hedgehog_size)) &&
       y_min_hedgehog < (y_max_obstacle))
    {
      return true;
    }
  }
    return false;
}

bool is_touching_obstacle_top(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    int y_min_obstacle = obstacle.getPosition().y;
    int y_max_hedgehog = hedgehog.getPosition().y + (2 * hedgehog.getSize());

    int x_min_hedgehog = hedgehog.getPosition().x;
    int x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
    int x_min_obstacle = obstacle.getPosition().x;

    if(y_max_hedgehog == y_min_obstacle &&
       x_min_hedgehog > (x_min_obstacle - (2 * hedgehog_size)) &&
       x_min_hedgehog < (x_max_obstacle))
    {
      return true;
    }
  }
  return false;
}
