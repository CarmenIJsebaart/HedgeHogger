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

void append(
  const std::vector<Vehicle>& add_these_vehicles,
  std::vector<Vehicle>& add_vehicles_here)
{
  for (const Vehicle& veh: add_these_vehicles)
  {
    add_vehicles_here.push_back(veh);
  }
}

std::vector<Vehicle> create_vehicles(
  const int hedgehog_size,
  const int window_width) noexcept
{
  std::vector<Vehicle> vehicles;
  append(create_bikes_lower_lane(window_width, hedgehog_size), vehicles);
  append(create_bikes_upper_lane(window_width, hedgehog_size), vehicles);
  append(create_cars_lower_lane(window_width, hedgehog_size), vehicles);
  append(create_cars_upper_lane(window_width, hedgehog_size), vehicles);
  append(create_trucks_lower_lane(window_width, hedgehog_size), vehicles);
  append(create_trucks_upper_lane(window_width, hedgehog_size), vehicles);
  append(create_walkers_upper_lane(window_width, hedgehog_size), vehicles);
  assert(vehicles.size() == 34);
  return vehicles;
}

void drive(
  std::vector<Vehicle> &vehicles)
{
  for(auto &vehicle : vehicles)
  {
    if(vehicle.get_direction() == true)
    {
      const auto current_x_position = vehicle.get_position().x;
      auto new_x_position = current_x_position + vehicle.get_speed();
      vehicle.set_position(sf::Vector2f(new_x_position, vehicle.get_position().y));
    }
    else if(vehicle.get_direction() == false)
    {
      const auto current_x_position = vehicle.get_position().x;
      auto new_x_position = current_x_position - vehicle.get_speed();
      vehicle.set_position(sf::Vector2f(new_x_position, vehicle.get_position().y));
    }
  }
}

std::vector<Vehicle> create_bikes_lower_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
  for(int i = 0; i <= 5; ++i)
  {
    int x_vehicle = 50 + (i * 110);
    assert(50 + (i * 110) <= window_width);
    int y_vehicle = 510;
    assert(y_vehicle % hedgehog_size == 0);

    const double bike_speed = 0.8;

    Vehicle bike(
      sf::Vector2f(x_vehicle , y_vehicle),
      2 * hedgehog_size,
      2 * hedgehog_size,
      sf::Color::Cyan,
      bike_speed,
      true); //true -> drive to right
    vehicles.push_back(bike);
  }
  return vehicles;
}

std::vector<Vehicle> create_bikes_upper_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
  for(int i = 0; i <= 5; ++i)
  {
    int x_vehicle = 50 + (i * 110);
    assert(50 + (i * 110) <= window_width);
    int y_vehicle = 120;
    assert(y_vehicle % hedgehog_size == 0);

    const double bike_speed = 0.8;

    Vehicle bike(
      sf::Vector2f(x_vehicle , y_vehicle),
      2 * hedgehog_size,
      2 * hedgehog_size,
      sf::Color::Cyan,
      bike_speed,
      false); //false -> drive to left
    vehicles.push_back(bike);
  }
  return vehicles;
}

std::vector<Vehicle> create_cars_lower_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
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

    Vehicle car(
      sf::Vector2f(x_vehicle, y_vehicle),
      car_length,
      car_width,
      sf::Color::Yellow,
      car_speed,
      true); //true -> drive to right
    vehicles.push_back(car);
  }
  return vehicles;
}

std::vector<Vehicle> create_cars_upper_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
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

    Vehicle car(
      sf::Vector2f(x_vehicle, y_vehicle),
      car_length, car_width,
      sf::Color::Yellow,
      car_speed,
      false); //false -> drive to left
    vehicles.push_back(car);
  }
  return vehicles;
}

std::vector<Vehicle> create_trucks_lower_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
  for(int i = 0; i <= 2; ++i)
  {
    int x_vehicle = 50 + (i * 240);
    assert(50 + (i * 240) <= window_width);
    int y_vehicle = 450;
    assert(y_vehicle % hedgehog_size == 0);

    const double truck_speed = 1.2;

    Vehicle truck(
      sf::Vector2f(x_vehicle , y_vehicle),
      100,
      2 * hedgehog_size,
      sf::Color::Blue,
      truck_speed,
      true); //true -> drive to right
    vehicles.push_back(truck);
  }
  return vehicles;
}

std::vector<Vehicle> create_trucks_upper_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
  for(int i = 0; i <= 2; ++i)
  {
    int x_vehicle = 50 + (i * 240);
    assert(50 + (i * 240) <= window_width);
    int y_vehicle = 180;
    assert(y_vehicle % hedgehog_size == 0);

    const double truck_speed = 1.2;

    Vehicle truck(
      sf::Vector2f(x_vehicle , y_vehicle),
      100,
      2 * hedgehog_size,
      sf::Color::Blue,
      truck_speed,
      false); //false -> drive to left
    vehicles.push_back(truck);
  }
  return vehicles;
}

std::vector<Vehicle> create_walkers_upper_lane(
  const int window_width,
  const int hedgehog_size)
{
  std::vector<Vehicle> vehicles;
  for(int i = 0; i <= 7; ++i)
  {
    int x_vehicle = 10 + (i * 80);
    assert(10 + (i * 80) <= window_width);
    int y_vehicle = 75;
    assert(y_vehicle % hedgehog_size == 0);

    const double truck_speed = 0.4;

    Vehicle walker(
      sf::Vector2f(x_vehicle , y_vehicle),
      hedgehog_size,
      hedgehog_size,
      sf::Color::Magenta,
      truck_speed,
      false); //false -> drive to left
    vehicles.push_back(walker);
  }
  return vehicles;
}

sf::RectangleShape get_shape(
  const Vehicle &vehicle)
{
  sf::RectangleShape vehicle_shape;
  vehicle_shape.setSize(sf::Vector2f(vehicle.get_length(), vehicle.get_width()));
  vehicle_shape.setPosition(vehicle.get_position());
  vehicle_shape.setFillColor(vehicle.get_color());
  return vehicle_shape;
}

void keep_vehicles_in_window(
  const sf::RenderWindow &window,
  std::vector<Vehicle> &vehicles)
{
  for(auto &vehicle : vehicles)
  {
    sf::Vector2f position = vehicle.get_position();
    float position_x = position.x;
    if(vehicle.get_direction() == true && //true -> drive to right
       position_x >= window.getSize().x)
    {
      set_vehicle_left(vehicle);
    }
    else if(vehicle.get_direction() == false && //false -> drive to left
            position_x <= -vehicle.get_length())
    {
      set_vehicle_right(vehicle, window.getSize().x);
    }
  }
}

void Vehicle::set_position(
  const sf::Vector2f &any_position)
{
  position = any_position;
}

void set_vehicle_left(Vehicle &vehicle)
{
  auto pos = vehicle.get_position();
  pos.x = -vehicle.get_length();
  vehicle.set_position(pos);
}

void set_vehicle_right(
  Vehicle &vehicle,
  const int window_width)
{
  auto pos = vehicle.get_position();
  pos.x = window_width;
  vehicle.set_position(pos);
}
