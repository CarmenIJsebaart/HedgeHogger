#include "hedgehog.h"

#include <stdexcept>

Hedgehog::Hedgehog(
  const sf::Vector2f &any_position,
  float size,
  sf::Color color,
  const int window_size)
  : color{color},
    position{any_position},
    size{size},
    window_size{window_size}
{
}

bool are_colliding(
  const std::vector<Vehicle> &vehicles,
  const Hedgehog &hedgehog)
{
  for(auto &vehicle : vehicles)
  {
    bool x_direction = has_collision_x_direction(hedgehog, vehicle);
    bool y_direction = has_collision_y_direction(hedgehog, vehicle);

    if(x_direction && y_direction)
    {
      return true;
    }
  }
  return false;
}

Hedgehog create_hedgehog(
  const int window_size)
{
  const int size = 15;
  Hedgehog hedgehog(
    sf::Vector2f((window_size / 2) - size, window_size - (size * 2)),
    size,
    sf::Color::Red,
    window_size);

  return hedgehog;
}

sf::CircleShape get_shape(
  const Hedgehog &hedgehog)
{
  sf::CircleShape hedgehog_shape;
  hedgehog_shape.setRadius(hedgehog.get_size());
  hedgehog_shape.setPosition(hedgehog.get_position());
  hedgehog_shape.setFillColor(hedgehog.get_color());
  return hedgehog_shape;
}

bool has_collision_x_direction(
  const Hedgehog &hedgehog,
  const Vehicle &vehicle)
{
    const auto  x_min_vehicle = vehicle.get_position().x;
    const auto  x_max_vehicle = vehicle.get_position().x + vehicle.get_length();
    const auto  x_min_hedgehog = hedgehog.get_position().x;
    const auto  x_max_hedgehog = hedgehog.get_position().x + (2 * hedgehog.get_size());

    return(x_min_hedgehog > x_min_vehicle && x_min_hedgehog < x_max_vehicle) ||
     (x_max_hedgehog > x_min_vehicle && x_max_hedgehog < x_max_vehicle) ||
     (x_min_hedgehog <= x_min_vehicle && x_max_hedgehog >= x_max_vehicle);
}

bool has_collision_y_direction(
  const Hedgehog &hedgehog,
  const Vehicle &vehicle)
{
    const auto y_min_vehicle = vehicle.get_position().y;
    const auto y_max_vehicle = vehicle.get_position().y + vehicle.get_width();
    const auto y_min_hedgehog = hedgehog.get_position().y;
    const auto y_max_hedgehog = hedgehog.get_position().y + (2 * hedgehog.get_size());

    return(y_min_hedgehog > y_min_vehicle && y_min_hedgehog < y_max_vehicle) ||
          (y_max_hedgehog > y_min_vehicle && y_max_hedgehog < y_max_vehicle) ||
          (y_min_hedgehog <= y_min_vehicle && y_max_hedgehog >= y_max_vehicle);
}

bool is_touching_obstacle_bottom(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_max_obstacle = obstacle.get_position().y + obstacle.get_width();
    const auto y_min_hedgehog = hedgehog.get_position().y;

    const auto x_min_obstacle = obstacle.get_position().x;
    const auto x_max_obstacle = obstacle.get_position().x + obstacle.get_length();
    const auto x_min_hedgehog = hedgehog.get_position().x;

    if(y_min_hedgehog == y_max_obstacle &&
       x_min_hedgehog > (x_min_obstacle - (2 * hedgehog_size)) &&
       x_min_hedgehog < (x_max_obstacle))
    {
      return true;
    }
  }
    return false;
}

bool is_touching_obstacle_left(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_min_obstacle = obstacle.get_position().y;
    const auto y_max_obstacle = obstacle.get_position().y + obstacle.get_width();
    const auto y_min_hedgehog = hedgehog.get_position().y;

    const auto x_min_obstacle = obstacle.get_position().x;
    const auto x_max_hedgehog = hedgehog.get_position().x + (2 * hedgehog.get_size());

    if(x_max_hedgehog == x_min_obstacle &&
       y_min_hedgehog > (y_min_obstacle - (2 * hedgehog_size)) &&
       y_min_hedgehog < (y_max_obstacle))
    {
      return true;
    }
  }
  return false;
}

bool is_touching_obstacle_right(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_min_obstacle = obstacle.get_position().y;
    const auto y_max_obstacle = obstacle.get_position().y + obstacle.get_width();
    const auto y_min_hedgehog = hedgehog.get_position().y;

    const auto x_max_obstacle = obstacle.get_position().x + obstacle.get_length();
    const auto x_min_hedgehog = hedgehog.get_position().x;

    if(x_min_hedgehog == x_max_obstacle &&
       y_min_hedgehog > (y_min_obstacle - (2 * hedgehog_size)) &&
       y_min_hedgehog < (y_max_obstacle))
    {
      return true;
    }
  }
    return false;
}

bool is_touching_obstacle_top(
  const std::vector<Obstacle> &obstacles,
  const Hedgehog &hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_min_obstacle = obstacle.get_position().y;
    const auto y_max_hedgehog = hedgehog.get_position().y + (2 * hedgehog.get_size());

    const auto x_min_hedgehog = hedgehog.get_position().x;
    const auto x_max_obstacle = obstacle.get_position().x + obstacle.get_length();
    const auto x_min_obstacle = obstacle.get_position().x;

    if(y_max_hedgehog == y_min_obstacle &&
       x_min_hedgehog > (x_min_obstacle - (2 * hedgehog_size)) &&
       x_min_hedgehog < (x_max_obstacle))
    {
      return true;
    }
  }
    return false;
}

void move(
  const sf::RenderWindow &window,
  Hedgehog &hedgehog,
  const std::vector<Obstacle> &obstacles)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    move_down(hedgehog, window, obstacles);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    move_left(hedgehog, obstacles);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    move_right(hedgehog, window, obstacles);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    move_up(hedgehog, obstacles);
  }
}

void move_down(
  Hedgehog &hedgehog,
  const sf::RenderWindow &window,
  const std::vector<Obstacle> &obstacles)
{
  if(hedgehog.get_position().y + (2 * hedgehog.get_size()) < window.getSize().y &&
     is_touching_obstacle_top(obstacles, hedgehog, hedgehog.get_size()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.get_position();
    hedgehog_position.y = hedgehog.get_position().y + (hedgehog.get_size());
    hedgehog.set_position(hedgehog_position);
   }
}

void move_left(Hedgehog &hedgehog,
  const std::vector<Obstacle> &obstacles)
{
  if(hedgehog.get_position().x >= hedgehog.get_size() &&
     is_touching_obstacle_right(obstacles, hedgehog, hedgehog.get_size()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.get_position();
    hedgehog_position.x = hedgehog.get_position().x - (hedgehog.get_size());
    hedgehog.set_position(hedgehog_position);
  }
}

void move_right(
  Hedgehog &hedgehog,
  const sf::RenderWindow &window,
  const std::vector<Obstacle> &obstacles)
{
  if(hedgehog.get_position().x <= (window.getSize().x - (3 * hedgehog.get_size())) &&
     is_touching_obstacle_left(obstacles, hedgehog, hedgehog.get_size()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.get_position();
    hedgehog_position.x = hedgehog.get_position().x + (hedgehog.get_size());
    hedgehog.set_position(hedgehog_position);
  }
}

void move_up(
  Hedgehog &hedgehog,
  const std::vector<Obstacle> &obstacles)
{
  if(hedgehog.get_position().y >= hedgehog.get_size() &&
     is_touching_obstacle_bottom(obstacles, hedgehog, hedgehog.get_size()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.get_position();
    hedgehog_position.y = hedgehog.get_position().y - (hedgehog.get_size());
    hedgehog.set_position(hedgehog_position);
  }
}

void Hedgehog::set_position(
  const sf::Vector2f &any_position)
{
  if(any_position.x < 0 ||
     any_position.x + (2 * size) > window_size  ||
     any_position.y < 0 ||
     any_position.y + (2 * size) > window_size)
  {
    throw std::invalid_argument("position has to be on screen");
  }
  position = any_position;
}
