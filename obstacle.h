#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cassert>
#include <SFML/Graphics.hpp>

class Obstacle
{
    sf::Color color;
    int length;
    sf::Vector2f position;
    int width;
public:
  Obstacle(
    const sf::Vector2f position,
    int length,
    int width,
    sf::Color color);

  int get_length() const { return length; }
  sf::Vector2f get_position() const;
  sf::RectangleShape get_shape();
  int get_width() const { return width; }
};

std::vector<Obstacle> create_obstacles(
  const int window_width,
  const int hedgehog_size);

#endif // OBSTACLE_H
