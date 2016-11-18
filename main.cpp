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

  Truck truck(sf::Vector2f(0.0,500.0));

  Car car;

  /*sf::RectangleShape car;
  const int car_length = 50;
  const int car_width = 25;
  car.setSize(sf::Vector2f(car_length, car_width));
  car.setFillColor(sf::Color::Yellow);
  int car_x_position = (window_width / 2);
  int car_y_position = 500 + (0.5 * (30 - car_width)); //30 = truck_width
  car.setPosition(car_x_position, car_y_position);*/

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

      sf::Vector2f p = truck.getPosition();
      p.x += 1;
      truck.setPosition(p);

      //car_x_position += 1;
      //car.setPosition(car_x_position, car_y_position);
      clock.restart();
    }

    if(truck.getPosition().x >= 600)
    {
      sf::Vector2f p = truck.getPosition();
      p.x = -truck.get_length();
      truck.setPosition(p);
    }
    /*
    if(car.getPosition().x >= 600)
    {
      car_x_position = -car_length;
    } */

    window.clear();
    window.draw(hedgehog);
    window.draw(truck.getShape());
    window.draw(car.getShape());
    window.display();
  }
}
