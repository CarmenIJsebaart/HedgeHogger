#ifndef TRUCK_H
#define TRUCK_H

#include <SFML/Graphics.hpp>

class Truck
{
  const int length;
  const int width;
  sf::Vector2f position;
public:
  //Creat a Truck with 'position' as the initial position
  Truck(const sf::Vector2f &any_position);
  int get_length() const { return length; }
  sf::Vector2f getPosition();
  void setPosition(const sf::Vector2f &any_position);
  sf::RectangleShape getShape();
  int get_width() const { return width; }

};

#endif // TRUCK_H
