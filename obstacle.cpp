#include "obstacle.h"

Obstacle::Obstacle(const sf::Vector2f position, int length, int width, sf::Color color)
  : color{color},
    length{length},
    position{position},
    width{width}
{
}

void check_collision(Obstacle obstacle, Hedgehog hedgehog, bool &has_crashed)
{
  int y_min_obstacle = obstacle.getPosition().y;
  int y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
  int y_min_hedgehog = hedgehog.getPosition().y;
  int y_max_hedgehog = hedgehog.getPosition().y + (2 * hedgehog.getSize());

  int x_min_obstacle = obstacle.getPosition().x;
  int x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
  int x_min_hedgehog = hedgehog.getPosition().x;
  int x_max_hedgehog = hedgehog.getPosition().x + (2 * hedgehog.getSize());

  if((y_min_hedgehog > y_min_obstacle && y_min_hedgehog < y_max_obstacle) ||
     (y_max_hedgehog > y_min_obstacle && y_max_hedgehog < y_max_obstacle) ||
     (y_min_hedgehog <= y_min_obstacle && y_max_hedgehog >= y_max_obstacle))
  {
    if((x_min_hedgehog > x_min_obstacle && x_min_hedgehog < x_max_obstacle) ||
       (x_max_hedgehog > x_min_obstacle && x_max_hedgehog < x_max_obstacle) ||
       (x_min_hedgehog <= x_min_obstacle && x_max_hedgehog >= x_max_obstacle))
    {
      has_crashed = true;
    }
  }
}

std::vector<Obstacle> create_obstacles(const int window_width, const int hedgehog_size) noexcept
{
  std::vector<Obstacle> obstacles;
  const int obstacle_width = 30;
  const int obstacle_length = 120;
  assert(obstacle_length % (2 * hedgehog_size) == 0);

  for(int i = 0; i <= 2; ++i)
  {
    int x = 240 * i;
    assert(240 * i + obstacle_length <= window_width);
    Obstacle obstacle(sf::Vector2f(x, 300), obstacle_length, obstacle_width, sf::Color::Green);
    obstacles.push_back(obstacle);
  }

  assert(obstacles.size() == 3);
  return obstacles;
}

sf::Vector2f Obstacle::getPosition() const
{
  return position;
}

sf::RectangleShape Obstacle::getShape()
{
  sf::RectangleShape vehicle_shape;
  vehicle_shape.setSize(sf::Vector2f(length, width));
  vehicle_shape.setPosition(position);
  vehicle_shape.setFillColor(color);
  return vehicle_shape;
}
