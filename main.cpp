#include <cassert>
#include "hedgehog.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "vehicle.h"

int main()
{
  const int window_height = 600;
  const int window_width = 600;
  sf::RenderWindow window(sf::VideoMode(window_width, window_height),
                          "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);

  const int size = 15;
  Hedgehog hedgehog(sf::Vector2f((window_width / 2) - size,
                                  window_height - (size * 2)), size, sf::Color::Red);
  Vehicle truck1(sf::Vector2f(0  , 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle truck2(sf::Vector2f(300, 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle car1(sf::Vector2f(100, 390), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car2(sf::Vector2f(300, 390), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car3(sf::Vector2f(500, 390), 50, 25, sf::Color::Yellow, 1.5);
  assert(window_height % hedgehog.get_size() == 0);

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
          if(hedgehog.getPosition().x >= (2 * hedgehog.get_size()))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              hedgehog_position.x = hedgehog.getPosition().x - (2 * hedgehog.get_size());
              hedgehog.setPosition(hedgehog_position);
            }
          }
          if(hedgehog.getPosition().x <= (window_width - (4 * hedgehog.get_size())))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              hedgehog_position.x = hedgehog.getPosition().x + (2 * hedgehog.get_size());
              hedgehog.setPosition(hedgehog_position);
            }
          }
          if(hedgehog.getPosition().y >= hedgehog.get_size())
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              hedgehog_position.y = hedgehog.getPosition().y - (2 * hedgehog.get_size());
              hedgehog.setPosition(hedgehog_position);
            }
          }
        default:
          break;
      }
    }

    const double update_time = 10; //milliseconds

    if(clock.getElapsedTime().asMilliseconds() >= update_time)
    {
      truck1.drive();
      truck2.drive();
      car1.drive();
      car2.drive();
      car3.drive();
      clock.restart();
    }

    if(truck1.getPosition().x >= 600)
    {
      sf::Vector2f truck_position = truck1.getPosition();
      truck_position.x = -truck1.get_length();
      truck1.setPosition(truck_position);
    }

    if(car1.getPosition().x >= 600)
    {
      sf::Vector2f car_position = car1.getPosition();
      car_position.x = -car1.get_length() - 50;
      car1.setPosition(car_position);
    }

    window.clear();
    window.draw(hedgehog.getShape());
    window.draw(truck1.getShape());
    window.draw(truck2.getShape());
    window.draw(car1.getShape());
    window.draw(car2.getShape());
    window.draw(car3.getShape());
    window.display();
  }
}
