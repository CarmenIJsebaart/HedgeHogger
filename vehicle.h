#ifndef VEHICLE_H
#define VEHICLE_H

#include <cassert>
#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "vehicletype.h"

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

void check_collision(Vehicle vehicle, Hedgehog hedgehog, bool &has_crashed);
void check_direction(sf::RenderWindow * window, Vehicle &vehicle);
std::vector<Vehicle> create_vehicles(const int hedgehog_size, const int window_width) noexcept;

#endif // VEHICLE_H
