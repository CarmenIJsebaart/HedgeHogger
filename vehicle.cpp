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

std::vector<Vehicle> create_vehicles(const int hedgehog_size, const int window_width) noexcept
{
  std::vector<Vehicle> vehicles;
  //Create cars
  for(int i = 0; i <= 3; ++i)
  {
    int x = 100 + (i * 160);
    assert(100 + (i * 160) <= window_width);
    int y = 375;
    assert(y % hedgehog_size == 0);

    const int car_length = 50;
    const int car_width = 30;
    assert(car_width % hedgehog_size == 0);
    assert(100 + (i * 160) <= window_width);

    Vehicle car(sf::Vector2f(x, y), car_length, car_width, sf::Color::Yellow, 1.5);
    vehicles.push_back(car);
  }

  //Create trucks
  for(int i = 0; i <= 2; ++i)
  {
    int x = 50 + (i * 240);
    assert(50 + (i * 240) <= window_width);
    int y = 450;
    assert(y % hedgehog_size == 0);

    Vehicle truck(sf::Vector2f(x , y), 100, 2 * hedgehog_size, sf::Color::Blue, 1);
    vehicles.push_back(truck);
  }

  assert(vehicles.size() == 7);
  return vehicles;
}

void Vehicle::drive()
{
  position.x = position.x + speed;
}

sf::Vector2f Vehicle::getPosition() const
{
  return position;
}

void Vehicle::setPosition(const sf::Vector2f &any_position)
{
  position = any_position;
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
}
