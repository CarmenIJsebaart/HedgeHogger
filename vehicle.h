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
  Vehicle(const sf::Vector2f &any_position, int length, int width, sf::Color color, float speed, bool direction);

  sf::Color getColor() const noexcept { return color; }
  bool getDirection() const { return direction; }
  int getLength() const { return length; }
  sf::Vector2f getPosition() const;
  sf::RectangleShape getShape();
  int getSpeed() const { return speed; }
  int getWidth() const { return width; }

  void setPosition(const sf::Vector2f &any_position);

  void drive();
  void set_vehicle_left();
  void set_vehicle_right(const int window_width);
};

void append(const std::vector<Vehicle>& add_these_vehicles, std::vector<Vehicle>& add_vehicles_here);
std::vector<Vehicle> create_vehicles(const int hedgehog_size, const int window_width) noexcept;
std::vector<Vehicle> create_bikes_lower_lane(const int window_width, const int hedgehog_size);
std::vector<Vehicle> create_bikes_upper_lane(const int window_width, const int hedgehog_size);
std::vector<Vehicle> create_cars_lower_lane(const int window_width, const int hedgehog_size);
std::vector<Vehicle> create_cars_upper_lane(const int window_width, const int hedgehog_size);
std::vector<Vehicle> create_trucks_lower_lane(const int window_width, const int hedgehog_size);
std::vector<Vehicle> create_trucks_upper_lane(const int window_width, const int hedgehog_size);
std::vector<Vehicle> create_walkers_upper_lane(const int window_width, const int hedgehog_size);
void keep_vehicles_in_window(sf::RenderWindow * window, std::vector<Vehicle> &vehicles);

#endif // VEHICLE_H
