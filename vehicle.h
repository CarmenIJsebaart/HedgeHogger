#ifndef VEHICLE_H
#define VEHICLE_H

#include <cassert>
#include <SFML/Graphics.hpp>
#include "hedgehog.h"

class Vehicle
{
  sf::Color color;
  int length;
  sf::Vector2f position;
  float speed;
  int width;
public:
  //Create a Vehicle with 'position' as the initial position
  Vehicle(const sf::Vector2f &any_position, int length, int width, sf::Color color, float speed);

  sf::Color getColor() const noexcept { return color; }
  int getLength() const {return length;}
  sf::Vector2f getPosition() const;
  sf::RectangleShape getShape();
  int getSpeed() const { return speed; }
  int getWidth() const { return width; }

  void setPosition(const sf::Vector2f &any_position);

  void drive();
  void set_vehicle_left();
};

void check_collision(Vehicle vehicle, Hedgehog hedgehog, bool &has_crashed);

std::vector<Vehicle> create_vehicles(const float size) noexcept;

#endif // VEHICLE_H
