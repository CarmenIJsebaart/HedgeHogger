#include "obstacle.h"

Obstacle::Obstacle(
  const sf::Vector2f position,
  int length, int width,
  sf::Color color)
  : color{color},
    length{length},
    position{position},
    width{width}
{
}

std::vector<Obstacle> create_obstacles(
  const int window_width,
  const int hedgehog_size) noexcept
{
  std::vector<Obstacle> obstacles;
  const int obstacle_width = 30;
  const int obstacle_length = 120;
  assert(obstacle_length % (2 * hedgehog_size) == 0);

  for(int i = 0; i <= 2; ++i)
  {
    int x_obstacle = 240 * i;
    assert(240 * i + obstacle_length <= window_width);
    Obstacle obstacle(
      sf::Vector2f(x_obstacle, 300),
      obstacle_length,
      obstacle_width,
      sf::Color::Green);
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
