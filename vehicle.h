#ifndef VEHICLE_H
#define VEHICLE_H

#include <SFML/Graphics.hpp>

class Vehicle
{
  int length;
  int width;
  float speed;
  sf::Vector2f position;
  sf::Color color;
public:
  //Create a Vehicle with 'position' as the initial position
  Vehicle(const sf::Vector2f &any_position, int length, int width, sf::Color color, float speed);
  int get_length() const {return length;}
  sf::Vector2f getPosition();
  void setPosition(const sf::Vector2f &any_position);
  sf::RectangleShape getShape();
  int get_width() const { return width; }
  void drive();
};

#endif // VEHICLE_H
