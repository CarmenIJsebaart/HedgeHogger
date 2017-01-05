#ifndef HEDGEHOG_H
#define HEDGEHOG_H

#include <SFML/Graphics.hpp>

#include "obstacle.h"
#include "vehicle.h"

class Hedgehog
{
  sf::Color color;
  sf::Vector2f position;
  float size;
public:
  //Create the Hedgehog with 'position' as the initial position
  Hedgehog(const sf::Vector2f &any_position, float size, sf::Color color);
  sf::Color getColor() const noexcept { return color; }
  sf::Vector2f getPosition() const noexcept;
  void setPosition(const sf::Vector2f &any_position);
  sf::CircleShape getShape();
  float getSize() const noexcept { return size; }
};

bool are_colliding(std::vector<Vehicle> vehicles, Hedgehog hedgehog);
Hedgehog create_hedgehog(const int window_height, const int window_width);
void move(sf::RenderWindow * window, Hedgehog &hedgehog, std::vector<Obstacle> obstacles);
bool has_collision_x_direction(Hedgehog hedgehog, Vehicle vehicle);
bool has_collision_y_direction(Hedgehog hedgehog, Vehicle vehicle);
bool is_touching_obstacle_bottom(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size);
bool is_touching_obstacle_left(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size);
bool is_touching_obstacle_right(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size);
bool is_touching_obstacle_top(std::vector<Obstacle> obstacles, Hedgehog hedgehog, const int hedgehog_size);
void move_down(Hedgehog &hedgehog, sf::RenderWindow * window, std::vector<Obstacle> obstacles);
void move_left(Hedgehog &hedgehog, std::vector<Obstacle> obstacles);
void move_right(Hedgehog &hedgehog, sf::RenderWindow * window, std::vector<Obstacle> obstacles);
void move_up(Hedgehog &hedgehog, std::vector<Obstacle> obstacles);

#endif // HEDGEHOG_H
