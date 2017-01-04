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
  std::vector<Vehicle> vehicles = create_vehicles(hedgehog.getSize(), window->getSize().x);

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
          move(window, hedgehog);
          break;
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
