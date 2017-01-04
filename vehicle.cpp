#include "hedgehog.h"
#include "vehicle.h"

Vehicle::Vehicle(const sf::Vector2f &any_position, int length, int width, sf::Color color, float speed)
  : color{color},
    length{length},
    position{any_position},
    speed{speed},
    width{width}
{
}

void check_collision(Vehicle vehicle, Hedgehog hedgehog, bool &has_crashed)
{
  int y_min_vehicle = vehicle.getPosition().y;
  int y_max_vehicle = vehicle.getPosition().y + vehicle.getWidth();
  int y_min_hedgehog = hedgehog.getPosition().y;
  int y_max_hedgehog = hedgehog.getPosition().y + (2 * hedgehog.getSize());

  int x_min_vehicle = vehicle.getPosition().x;
  int x_max_vehicle = vehicle.getPosition().x + vehicle.getLength();
  int x_min_hedgehog = hedgehog.getPosition().x;
  int x_max_hedgehog = hedgehog.getPosition().x + (2 * hedgehog.getSize());

  if((y_min_hedgehog > y_min_vehicle && y_min_hedgehog < y_max_vehicle) ||
      (y_max_hedgehog > y_min_vehicle && y_max_hedgehog < y_max_vehicle) ||
      (y_min_hedgehog <= y_min_vehicle && y_max_hedgehog >= y_max_vehicle))
  {
    if((x_min_hedgehog > x_min_vehicle && x_min_hedgehog < x_max_vehicle) ||
        (x_max_hedgehog > x_min_vehicle && x_max_hedgehog < x_max_vehicle) ||
        (x_min_hedgehog <= x_min_vehicle && x_max_hedgehog >= x_max_vehicle))
    {
      has_crashed = true;
    }
  }
}

std::vector<Vehicle> create_vehicles(const float size) noexcept
{
  Vehicle truck1(sf::Vector2f(50 , 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle truck2(sf::Vector2f(283, 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle truck3(sf::Vector2f(516, 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle car1(sf::Vector2f(100, 400), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car2(sf::Vector2f(262, 400), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car3(sf::Vector2f(424, 400), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car4(sf::Vector2f(586, 400), 50, 25, sf::Color::Yellow, 1.5);

  std::vector<Vehicle> vehicle_vector;
  vehicle_vector.push_back(truck1);
  vehicle_vector.push_back(truck2);
  vehicle_vector.push_back(truck3);
  vehicle_vector.push_back(car1);
  vehicle_vector.push_back(car2);
  vehicle_vector.push_back(car3);
  vehicle_vector.push_back(car4);
  assert(vehicle_vector.size() == 7);

  return vehicle_vector;
}

void Vehicle::drive()
{
  position.x = position.x + speed;
  this->position = position;
}

sf::Vector2f Vehicle::getPosition() const
{
  return position;
}

void Vehicle::setPosition(const sf::Vector2f &any_position)
{
  this->position = any_position;
}

sf::RectangleShape Vehicle::getShape()
{
  sf::RectangleShape vehicle_shape;
  vehicle_shape.setSize(sf::Vector2f(length, width));
  vehicle_shape.setPosition(position);
  vehicle_shape.setFillColor(color);
  return vehicle_shape;
}

void Vehicle::set_vehicle_left()
{
  position.x = -length;
  this->position = position;
}
