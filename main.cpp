#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "vehicle.h"
#include "window.h"

int main()
{
  sf::RenderWindow * window = create_window();
  Hedgehog hedgehog = create_hedgehog(window->getSize().x, window->getSize().y);
  std::vector<Vehicle> vehicles = create_vehicles(hedgehog.getSize());

  sf::Clock clock;
  sf::Font font;
  font.loadFromFile("arial.ttf");

  while(window->isOpen())
  {
    sf::Event event;

    while(window->pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window->close();
          break;
        case sf::Event::KeyPressed:
          if(hedgehog.getPosition().x >= (2 * hedgehog.getSize()))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              --hedgehog_position.x;
              //hedgehog_position.x = hedgehog.getPosition().x - (2 * hedgehog.getSize());
              hedgehog.setPosition(hedgehog_position);
            }
          }
          if(hedgehog.getPosition().x <= (window->getSize().x - (4 * hedgehog.getSize())))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              ++hedgehog_position.x;
              //hedgehog_position.x = hedgehog.getPosition().x + (2 * hedgehog.getSize());
              hedgehog.setPosition(hedgehog_position);
            }
          }
          if(hedgehog.getPosition().y >= hedgehog.getSize())
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              --hedgehog_position.y;
              //hedgehog_position.y = hedgehog.getPosition().y - (2 * hedgehog.getSize());
              hedgehog.setPosition(hedgehog_position);
            }
          }
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
              sf::Vector2f hedgehog_position = hedgehog.getPosition();
              ++hedgehog_position.y;
              //hedgehog_position.y = hedgehog.getPosition().y - (2 * hedgehog.getSize());
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
      for(auto &vehicle : vehicles)
      {
         vehicle.drive();
      }
      clock.restart();
    }

    sf::Text text;
    text.setFont(font);
    text.setPosition(100,100);
    text.setColor(sf::Color::White);
    bool has_crashed = false;

    for(auto &vehicle : vehicles)
    {
      check_collision(vehicle, hedgehog, has_crashed);
      if (has_crashed) { text.setString("crash"); }
    }

    for(auto &vehicle : vehicles)
    {
      sf::Vector2f position = vehicle.getPosition();
      float position_x = position.x;
      if(position_x >= 600)
      {
        vehicle.set_vehicle_left();
      }
    }

    window->clear();
    window->draw(hedgehog.getShape());
    for(auto &vehicle : vehicles)
    {
      window->draw(vehicle.getShape());
    }

    window->draw(text);
    window->display();
  }
}
