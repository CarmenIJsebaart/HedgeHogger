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
  const int hedgehog_size)
{
  if (window_width <= 0)
  {
    throw std::invalid_argument("window width has to be positive");
  }
  if (hedgehog_size <= 0)
  {
    throw std::invalid_argument("hedgehog size has to be positive");
  }
  const int obstacle_width = 30;
  const int obstacle_length = 120;
  const int gap_length = 120; //Open space between obstacles
  const int heart_distance{obstacle_length + gap_length}; //Distance between obstacles' centers
  if(obstacle_length % (2 * hedgehog_size) != 0)
  {
    throw std::invalid_argument("obstacles should fit to screen");
  }

  std::vector<Obstacle> obstacles;
  for(int i = 0; i <= 2; ++i)
  {
    const int x_obstacle{heart_distance * i};
    const int x_right_obstacle{x_obstacle + obstacle_length};
    if (x_right_obstacle > window_width)
    {
      throw std::invalid_argument("obstacles do not fit on window");
    }
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
