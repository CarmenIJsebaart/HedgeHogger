#ifndef VEHICLE_H
#define VEHICLE_H

#include <SFML/Graphics.hpp>

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
  void setPosition(const sf::Vector2f &any_position);
  sf::RectangleShape getShape();
  int getSpeed() const { return speed; }
  int getWidth() const { return width; }
  void drive();
  void set_vehicle_left();
};

#endif // VEHICLE_H
