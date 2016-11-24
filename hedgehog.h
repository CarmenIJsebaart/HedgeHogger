#ifndef HEDGEHOG_H
#define HEDGEHOG_H

#include <SFML/Graphics.hpp>

class Hedgehog
{
  int size;
  sf::Vector2f position;
  sf::Color color;
public:
  //Create the Hedgehog with 'position' as the initial position
  Hedgehog(const sf::Vector2f &any_position, int size, sf::Color color);
  sf::Vector2f getPosition();
  void setPosition(const sf::Vector2f &any_position);
  sf::CircleShape getShape();
  int get_size() const { return size; }
};


#endif // HEDGEHOG_H
