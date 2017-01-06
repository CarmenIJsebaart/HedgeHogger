#ifndef VEHICLE_H
#define VEHICLE_H

#include <cassert>
#include <SFML/Graphics.hpp>

class Vehicle
{
  bool direction;
  sf::Color color;
  int length;
  sf::Vector2f position;
  float speed;
  int width;
public:
  //Create a Vehicle with 'position' as the initial position
  Vehicle(
    const sf::Vector2f &any_position,
    int length,
    int width,
    sf::Color color,
    float speed,
    bool direction);

  sf::Color get_color() const noexcept { return color; }
  bool get_direction() const noexcept { return direction; }
  int get_length() const noexcept { return length; }
  sf::Vector2f get_position() const noexcept { return position; }
  double get_speed() const noexcept { return speed; }
  int get_width() const noexcept { return width; }

  void set_position(
    const sf::Vector2f &any_position);
};

void append(
  const std::vector<Vehicle> &add_these_vehicles,
  std::vector<Vehicle> &add_vehicles_here);
std::vector<Vehicle> create_vehicles(
  const int hedgehog_size,
  const int window_width) noexcept;
std::vector<Vehicle> create_bikes_lower_lane(
  const int window_width,
  const int hedgehog_size);
std::vector<Vehicle> create_bikes_upper_lane(
  const int window_width,
  const int hedgehog_size);
std::vector<Vehicle> create_cars_lower_lane(
  const int window_width,
  const int hedgehog_size);
std::vector<Vehicle> create_cars_upper_lane(
  const int window_width,
  const int hedgehog_size);
std::vector<Vehicle> create_trucks_lower_lane(
  const int window_width,
  const int hedgehog_size);
std::vector<Vehicle> create_trucks_upper_lane(
  const int window_width,
  const int hedgehog_size);
std::vector<Vehicle> create_walkers_upper_lane(
  const int window_width,
  const int hedgehog_size);
void drive(
  std::vector<Vehicle> &vehicles);
sf::RectangleShape get_shape(const Vehicle &vehicle);
void keep_vehicles_in_window(
  sf::RenderWindow * window,
  std::vector<Vehicle> &vehicles);
void set_vehicle_left(
  Vehicle &vehicle);
void set_vehicle_right(
  Vehicle &vehicle,
  const int window_width);

#endif // VEHICLE_H
