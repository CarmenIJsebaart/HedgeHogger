#include "hedgehog.h"

Hedgehog::Hedgehog(
  const sf::Vector2f &any_position,
  float size,
  sf::Color color)
  : color{color},
    position{any_position},
    size{size}
{
}

bool are_colliding(
  std::vector<Vehicle> vehicles,
  Hedgehog hedgehog)
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
  const int window_height,
  const int window_width)
{
  const int size = 15;
  Hedgehog hedgehog(
    sf::Vector2f((window_width / 2) - size, window_height - (size * 2)),
    size,
    sf::Color::Red);

  return hedgehog;
}

sf::Vector2f Hedgehog::getPosition() const noexcept
{
  return position;
}

bool has_collision_x_direction(Hedgehog hedgehog, Vehicle vehicle)
{
    const auto  x_min_vehicle = vehicle.getPosition().x;
    const auto  x_max_vehicle = vehicle.getPosition().x + vehicle.getLength();
    const auto  x_min_hedgehog = hedgehog.getPosition().x;
    const auto  x_max_hedgehog = hedgehog.getPosition().x + (2 * hedgehog.getSize());

    return(x_min_hedgehog > x_min_vehicle && x_min_hedgehog < x_max_vehicle) ||
     (x_max_hedgehog > x_min_vehicle && x_max_hedgehog < x_max_vehicle) ||
     (x_min_hedgehog <= x_min_vehicle && x_max_hedgehog >= x_max_vehicle);
}

bool has_collision_y_direction(Hedgehog hedgehog, Vehicle vehicle)
{
    const auto y_min_vehicle = vehicle.getPosition().y;
    const auto y_max_vehicle = vehicle.getPosition().y + vehicle.getWidth();
    const auto y_min_hedgehog = hedgehog.getPosition().y;
    const auto y_max_hedgehog = hedgehog.getPosition().y + (2 * hedgehog.getSize());

    return(y_min_hedgehog > y_min_vehicle && y_min_hedgehog < y_max_vehicle) ||
          (y_max_hedgehog > y_min_vehicle && y_max_hedgehog < y_max_vehicle) ||
          (y_min_hedgehog <= y_min_vehicle && y_max_hedgehog >= y_max_vehicle);
}

bool is_touching_obstacle_bottom(
  std::vector<Obstacle> obstacles,
  Hedgehog hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
    const auto y_min_hedgehog = hedgehog.getPosition().y;

    const auto x_min_obstacle = obstacle.getPosition().x;
    const auto x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
    const auto x_min_hedgehog = hedgehog.getPosition().x;

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
  std::vector<Obstacle> obstacles,
  Hedgehog hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_min_obstacle = obstacle.getPosition().y;
    const auto y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
    const auto y_min_hedgehog = hedgehog.getPosition().y;

    const auto x_min_obstacle = obstacle.getPosition().x;
    const auto x_max_hedgehog = hedgehog.getPosition().x + (2 * hedgehog.getSize());

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
  std::vector<Obstacle> obstacles,
  Hedgehog hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_min_obstacle = obstacle.getPosition().y;
    const auto y_max_obstacle = obstacle.getPosition().y + obstacle.getWidth();
    const auto y_min_hedgehog = hedgehog.getPosition().y;

    const auto x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
    const auto x_min_hedgehog = hedgehog.getPosition().x;

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
  std::vector<Obstacle> obstacles,
  Hedgehog hedgehog,
  const int hedgehog_size)
{
  for(auto &obstacle : obstacles)
  {
    const auto y_min_obstacle = obstacle.getPosition().y;
    const auto y_max_hedgehog = hedgehog.getPosition().y + (2 * hedgehog.getSize());

    const auto x_min_hedgehog = hedgehog.getPosition().x;
    const auto x_max_obstacle = obstacle.getPosition().x + obstacle.getLength();
    const auto x_min_obstacle = obstacle.getPosition().x;

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
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles)
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
  sf::RenderWindow * window,
  std::vector<Obstacle> obstacles)
{
  if(hedgehog.getPosition().y + (2 * hedgehog.getSize()) < window->getSize().y &&
     is_touching_obstacle_top(obstacles, hedgehog, hedgehog.getSize()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.getPosition();
    hedgehog_position.y = hedgehog.getPosition().y + (hedgehog.getSize());
    hedgehog.setPosition(hedgehog_position);
   }
}

void move_left(
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles)
{
  if(hedgehog.getPosition().x >= hedgehog.getSize() &&
     is_touching_obstacle_right(obstacles, hedgehog, hedgehog.getSize()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.getPosition();
    hedgehog_position.x = hedgehog.getPosition().x - (hedgehog.getSize());
    hedgehog.setPosition(hedgehog_position);
  }
}

void move_right(
  Hedgehog &hedgehog,
  sf::RenderWindow * window,
  std::vector<Obstacle> obstacles)
{
  if(hedgehog.getPosition().x <= (window->getSize().x - (3 * hedgehog.getSize())) &&
     is_touching_obstacle_left(obstacles, hedgehog, hedgehog.getSize()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.getPosition();
    hedgehog_position.x = hedgehog.getPosition().x + (hedgehog.getSize());
    hedgehog.setPosition(hedgehog_position);
  }
}

void move_up(
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles)
{
  if(hedgehog.getPosition().y >= hedgehog.getSize() &&
     is_touching_obstacle_bottom(obstacles, hedgehog, hedgehog.getSize()) == false)
  {
    sf::Vector2f hedgehog_position = hedgehog.getPosition();
    hedgehog_position.y = hedgehog.getPosition().y - (hedgehog.getSize());
    hedgehog.setPosition(hedgehog_position);
  }
}

void Hedgehog::setPosition(
  const sf::Vector2f &any_position)
{
  position = any_position;
}

sf::CircleShape Hedgehog::getShape()
{
  sf::CircleShape hedgehog_shape;
  hedgehog_shape.setRadius(size);
  hedgehog_shape.setPosition(position);
  hedgehog_shape.setFillColor(color);
  return hedgehog_shape;
}
