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
  Obstacle(const sf::Vector2f position, int length, int width, sf::Color color);
  sf::RectangleShape getShape();
};

std::vector<Obstacle> create_obstacles(const int window_width) noexcept;

#endif // OBSTACLE_H
