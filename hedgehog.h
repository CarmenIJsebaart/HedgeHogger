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
  int window_size;
public:
  //Create the Hedgehog with 'position' as the initial position
  Hedgehog(
    const sf::Vector2f &any_position,
    float size,
    sf::Color color,
    const int window_size);

  sf::Color get_color() const noexcept { return color; }
  sf::Vector2f get_position() const noexcept { return position; }
  float get_size() const noexcept { return size; }
  int get_window_size() const noexcept { return window_size; }

  void set_position(
    const sf::Vector2f &any_position);
};

bool are_colliding(
  const std::vector<Vehicle> &vehicles,
  const Hedgehog &hedgehog);
Hedgehog create_hedgehog(const int window_size);
bool has_collision_x_direction(
  const Hedgehog &hedgehog,
  const Vehicle &vehicle);
bool has_collision_y_direction(
  const Hedgehog &hedgehog,
  const Vehicle &vehicle);
bool is_touching_obstacle_bottom(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size);
bool is_touching_obstacle_left(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size);
bool is_touching_obstacle_right(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size);
bool is_touching_obstacle_top(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size);
void move(
  const sf::RenderWindow &window,
  Hedgehog &hedgehog,
  const std::vector<Obstacle> &obstacles);
void move_down(
  Hedgehog &hedgehog,
  const sf::RenderWindow &window,
  const std::vector<Obstacle> &obstacles);
void move_left(
  Hedgehog &hedgehog,
  const std::vector<Obstacle> &obstacles);
void move_right(Hedgehog &hedgehog,
  const sf::RenderWindow &window,
  const std::vector<Obstacle> &obstacles);
void move_up(
  Hedgehog &hedgehog,
  const std::vector<Obstacle> &obstacles);
sf::CircleShape get_shape(
  const Hedgehog &hedgehog);

#endif // HEDGEHOG_H
