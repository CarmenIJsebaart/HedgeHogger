#include "obstacle.h"

Obstacle::Obstacle(const sf::Vector2f position, int length, int width, sf::Color color)
  : color{color},
    length{length},
    position{position},
    width{width}
{
}

std::vector<Obstacle> create_obstacles(const int window_width) noexcept
{
  std::vector<Obstacle> obstacles;
  const int obstacle_width = 30;
  const int obstacle_length = 100;

  for(int i = 0; i <= 2; ++i)
  {
    int x = 250 * i;
    assert(250 * i + obstacle_length <= window_width);
    Obstacle obstacle(sf::Vector2f(x, 300), obstacle_length, obstacle_width, sf::Color::Green);
    obstacles.push_back(obstacle);
  }

  assert(obstacles.size() == 3);
  return obstacles;
}

sf::RectangleShape Obstacle::getShape()
{
  sf::RectangleShape vehicle_shape;
  vehicle_shape.setSize(sf::Vector2f(length, width));
  vehicle_shape.setPosition(position);
  vehicle_shape.setFillColor(color);
  return vehicle_shape;
}
