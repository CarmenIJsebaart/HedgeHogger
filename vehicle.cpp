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

std::vector<Vehicle> create_vehicles(const float size, const int window_width) noexcept
{
  std::vector<Vehicle> vehicle_vector;
  //Create trucks
  for(int i = 0; i <= 2; ++i)
  {
    int x = 50 + (i * 240);
    assert(50 + (i * 240) <= window_width);
    Vehicle truck(sf::Vector2f(x , 450), 100, 2 * size, sf::Color::Blue, 1);
    vehicle_vector.push_back(truck);
  }

  //Create cars
  for(int i = 0; i <= 3; ++i)
  {
    const int car_length = 50;
    const int car_width = 25;
    int x = 100 + (i * 160);
    assert(100 + (i * 160) <= window_width);
    Vehicle car(sf::Vector2f(x, 400), car_length, car_width, sf::Color::Yellow, 1.5);
    vehicle_vector.push_back(car);
  }
  assert(vehicle_vector.size() == 7);
  return vehicle_vector;
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
