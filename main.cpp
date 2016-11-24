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
  Vehicle truck1(sf::Vector2f(50  , 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle truck2(sf::Vector2f(283, 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle truck3(sf::Vector2f(516, 450), 100, 2 * size, sf::Color::Blue, 1);
  Vehicle car1(sf::Vector2f(100, 400), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car2(sf::Vector2f(262, 400), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car3(sf::Vector2f(424, 400), 50, 25, sf::Color::Yellow, 1.5);
  Vehicle car4(sf::Vector2f(586, 400), 50, 25, sf::Color::Yellow, 1.5);
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
      truck3.drive();
      car1.drive();
      car2.drive();
      car3.drive();
      car4.drive();
      clock.restart();
    }

    truck1.set_vehicle_left();
    truck2.set_vehicle_left();
    truck3.set_vehicle_left();
    car1.set_vehicle_left();
    car2.set_vehicle_left();
    car3.set_vehicle_left();
    car4.set_vehicle_left();

    window.clear();
    window.draw(hedgehog.getShape());
    window.draw(truck1.getShape());
    window.draw(truck2.getShape());
    window.draw(truck3.getShape());
    window.draw(car1.getShape());
    window.draw(car2.getShape());
    window.draw(car3.getShape());
    window.draw(car4.getShape());
    window.display();
  }
}
