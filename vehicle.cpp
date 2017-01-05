#include "vehicle.h"

Vehicle::Vehicle(
  const sf::Vector2f &any_position,
  int length,
  int width,
  sf::Color color,
  float speed,
  bool direction)
  : direction{direction},
    color{color},
    length{length},
    position{any_position},
    speed{speed},
    width{width}
{
}

bool are_colliding(
  Vehicle vehicle,
  Hedgehog hedgehog)
{
  int y_min_vehicle = vehicle.getPosition().y;
  int y_max_vehicle = vehicle.getPosition().y + vehicle.getWidth();
  int y_min_hedgehog = hedgehog.getPosition().y;
  int y_max_hedgehog = hedgehog.getPosition().y + (2 * hedgehog.getSize());

  int x_min_vehicle = vehicle.getPosition().x;
  int x_max_vehicle = vehicle.getPosition().x + vehicle.getLength();
  int x_min_hedgehog = hedgehog.getPosition().x;
  int x_max_hedgehog = hedgehog.getPosition().x + (2 * hedgehog.getSize());

  if(((y_min_hedgehog > y_min_vehicle && y_min_hedgehog < y_max_vehicle) ||
      (y_max_hedgehog > y_min_vehicle && y_max_hedgehog < y_max_vehicle) ||
      (y_min_hedgehog <= y_min_vehicle && y_max_hedgehog >= y_max_vehicle)) &&
     ((x_min_hedgehog > x_min_vehicle && x_min_hedgehog < x_max_vehicle) ||
      (x_max_hedgehog > x_min_vehicle && x_max_hedgehog < x_max_vehicle) ||
      (x_min_hedgehog <= x_min_vehicle && x_max_hedgehog >= x_max_vehicle)))
  {
      return true;
  }
  return false;
}

void keep_vehicle_in_window(
  sf::RenderWindow * window,
  Vehicle &vehicle)
{
  sf::Vector2f position = vehicle.getPosition();
  float position_x = position.x;
  if(vehicle.getDirection() == true) //true -> drive to right
  {
    if(position_x >= window->getSize().x)
    {
      vehicle.set_vehicle_left();
    }
  }
  else if(vehicle.getDirection() == false) //false -> drive to left
  {
    if(position_x <= -vehicle.getLength())
    {
      vehicle.set_vehicle_right(window->getSize().x);
    }
  }
}
std::vector<Vehicle> create_vehicles(
  const int hedgehog_size,
  const int window_width) noexcept
{
  std::vector<Vehicle> vehicles;
  //Create bikes lower lane
  for(int i = 0; i <= 5; ++i)
  {
    int x_vehicle = 50 + (i * 110);
    assert(50 + (i * 110) <= window_width);
    int y_vehicle = 510;
    assert(y_vehicle % hedgehog_size == 0);

    const double bike_speed = 0.8;

    Vehicle bike(sf::Vector2f(x_vehicle , y_vehicle), 2 * hedgehog_size, 2 * hedgehog_size, sf::Color::Cyan, bike_speed, true); //true -> drive to right
    vehicles.push_back(bike);
  }

  //Create bikes upper lane
  for(int i = 0; i <= 5; ++i)
  {
    int x_vehicle = 50 + (i * 110);
    assert(50 + (i * 110) <= window_width);
    int y_vehicle = 120;
    assert(y_vehicle % hedgehog_size == 0);

    const double bike_speed = 0.8;

    Vehicle bike(sf::Vector2f(x_vehicle , y_vehicle), 2 * hedgehog_size, 2 * hedgehog_size, sf::Color::Cyan, bike_speed, false); //false -> drive to left
    vehicles.push_back(bike);
  }

  //Create cars lower lane
  for(int i = 0; i <= 3; ++i)
  {
    int x_vehicle = 100 + (i * 160);
    assert(100 + (i * 160) <= window_width);
    int y_vehicle = 375;
    assert(y_vehicle % hedgehog_size == 0);

    const int car_length = 50;
    const int car_width = 30;
    assert(car_width % hedgehog_size == 0);
    assert(100 + (i * 160) <= window_width);

    const double car_speed = 1.8;

    Vehicle car(sf::Vector2f(x_vehicle, y_vehicle), car_length, car_width, sf::Color::Yellow, car_speed, true); //true -> drive to right
    vehicles.push_back(car);
  }

  //Create cars upper lane
  for(int i = 0; i <= 3; ++i)
  {
    int x_vehicle = 100 + (i * 160);
    assert(100 + (i * 160) <= window_width);
    int y_vehicle = 240;
    assert(y_vehicle % hedgehog_size == 0);

    const int car_length = 50;
    const int car_width = 30;
    assert(car_width % hedgehog_size == 0);
    assert(100 + (i * 160) <= window_width);

    const double car_speed = 1.8;

    Vehicle car(sf::Vector2f(x_vehicle, y_vehicle), car_length, car_width, sf::Color::Yellow, car_speed, false); //false -> drive to left
    vehicles.push_back(car);
  }

  //Create trucks lower lane
  for(int i = 0; i <= 2; ++i)
  {
    int x_vehicle = 50 + (i * 240);
    assert(50 + (i * 240) <= window_width);
    int y_vehicle = 450;
    assert(y_vehicle % hedgehog_size == 0);

    const double truck_speed = 1.2;

    Vehicle truck(sf::Vector2f(x_vehicle , y_vehicle), 100, 2 * hedgehog_size, sf::Color::Blue, truck_speed, true); //true -> drive to right
    vehicles.push_back(truck);
  }

  //Create trucks upper lane
  for(int i = 0; i <= 2; ++i)
  {
    int x_vehicle = 50 + (i * 240);
    assert(50 + (i * 240) <= window_width);
    int y_vehicle = 180;
    assert(y_vehicle % hedgehog_size == 0);

    const double truck_speed = 1.2;

    Vehicle truck(sf::Vector2f(x_vehicle , y_vehicle), 100, 2 * hedgehog_size, sf::Color::Blue, truck_speed, false); //false -> drive to left
    vehicles.push_back(truck);
  }

  //Create walkers upper lane
  for(int i = 0; i <= 7; ++i)
  {
    int x_vehicle = 10 + (i * 80);
    assert(10 + (i * 80) <= window_width);
    int y_vehicle = 75;
    assert(y_vehicle % hedgehog_size == 0);

    const double truck_speed = 0.4;

    Vehicle walker(sf::Vector2f(x_vehicle , y_vehicle), hedgehog_size, hedgehog_size, sf::Color::Magenta, truck_speed, false); //false -> drive to left
    vehicles.push_back(walker);
  }

  assert(vehicles.size() == 34);
  return vehicles;
}

void Vehicle::drive()
{
  if(direction == true)
  {
    position.x = position.x + speed;
  }
  else if(direction == false)
  {
    position.x = position.x - speed;
  }
}

sf::Vector2f Vehicle::getPosition() const
{
  return position;
}

void Vehicle::setPosition(
  const sf::Vector2f &any_position)
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

void Vehicle::set_vehicle_right(
  const int window_width)
{
  position.x = window_width;
}
