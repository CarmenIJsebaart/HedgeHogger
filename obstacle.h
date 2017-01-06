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

  sf::Color get_color() const noexcept { return color; }
  int get_length() const noexcept { return length; }
  sf::Vector2f get_position() const noexcept { return position; }
  int get_width() const noexcept { return width; }
};

std::vector<Obstacle> create_obstacles(
  const int window_width,
  const int hedgehog_size);
sf::RectangleShape get_shape(const Obstacle &obstacle);

#endif // OBSTACLE_H
