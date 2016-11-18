#include "car.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "truck.h"

int main()
{
  const int window_height = 600;
  const int window_width = 600;
  sf::RenderWindow window(sf::VideoMode(window_width, window_height), "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);

  sf::CircleShape hedgehog;
  const int hedgehog_size = 15;
  hedgehog.setRadius(hedgehog_size);
  hedgehog.setFillColor(sf::Color::Red);
  int hedgehog_x_position = (window_width / 2) - hedgehog_size;
  int hedgehog_y_position = window_height - (hedgehog_size * 2);
  hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));

  Truck truck(sf::Vector2f(0, 450));
  Car car(sf::Vector2f(window_width / 2, 452));

  sf::Clock clock;

  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          if(hedgehog_x_position >= (2 * hedgehog_size))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
              hedgehog_x_position = hedgehog_x_position - (2 * hedgehog_size);
              hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));
            }
          }
          if(hedgehog_x_position <= (window_width - (4 * hedgehog_size)))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
              hedgehog_x_position = hedgehog_x_position + (2 * hedgehog_size);
              hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));
            }
          }
          if(hedgehog_y_position >= hedgehog_size)
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
              hedgehog_y_position = hedgehog_y_position - (2 * hedgehog_size);
              hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));
            }
          }
        default:
          break;
      }
    }

    const double update_time = 10; //milliseconds

    if(clock.getElapsedTime().asMilliseconds() >= update_time)
    {
      sf::Vector2f truck_position = truck.getPosition();
      truck_position.x += 1;
      truck.setPosition(truck_position);

      sf::Vector2f car_position = car.getPosition();
      car_position.x += 1;
      car.setPosition(car_position);

      clock.restart();
    }

    if(truck.getPosition().x >= 600)
    {
      sf::Vector2f truck_position = truck.getPosition();
      truck_position.x = -truck.get_length();
      truck.setPosition(truck_position);
    }

    if(car.getPosition().x >= 600)
    {
      sf::Vector2f car_position = car.getPosition();
      car_position.x = -car.get_length();
      car.setPosition(car_position);
    }

    window.clear();
    window.draw(hedgehog);
    window.draw(truck.getShape());
    window.draw(car.getShape());
    window.display();
  }
}
