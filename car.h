#ifndef CAR_H
#define CAR_H

#include <SFML/Graphics.hpp>

class Car
{
  const int length;
  const int width;
  sf::Vector2f position;
public:
  //Create a Car with 'position' as the initial position
  Car(const sf::Vector2f &any_position);
  int get_length() const {return length;}
  sf::Vector2f getPosition();
  void setPosition(const sf::Vector2f &any_position);
  sf::RectangleShape getShape();
  int get_width() const { return width; }
};

#endif // CAR_H
