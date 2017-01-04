#ifndef HEDGEHOG_H
#define HEDGEHOG_H

#include <SFML/Graphics.hpp>

class Hedgehog
{
  sf::Color color;
  sf::Vector2f position;
  float size;
public:
  //Create the Hedgehog with 'position' as the initial position
  Hedgehog(const sf::Vector2f &any_position, float size, sf::Color color);
  sf::Color getColor() const noexcept { return color; }
  sf::Vector2f getPosition() const noexcept;
  void setPosition(const sf::Vector2f &any_position);
  sf::CircleShape getShape();
  float getSize() const noexcept { return size; }
};

Hedgehog create_hedgehog(const int window_height, const int window_width);
void move(sf::RenderWindow *window, Hedgehog &hedgehog);

#endif // HEDGEHOG_H
