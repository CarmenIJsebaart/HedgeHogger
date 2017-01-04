#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <cassert>
#include <SFML/Graphics.hpp>

#include "hedgehog.h"

class Obstacle
{
    sf::Color color;
    int length;
    sf::Vector2f position;
    int width;
public:
  Obstacle(const sf::Vector2f position, int length, int width, sf::Color color);

  int getLength() const { return length; }
  sf::Vector2f getPosition() const;
  sf::RectangleShape getShape();
  int getWidth() const { return width; }
};

void check_collision(Obstacle obstacle, Hedgehog hedgehog, bool &is_touched);
std::vector<Obstacle> create_obstacles(const int window_width, const int hedgehog_size) noexcept;

#endif // OBSTACLE_H
