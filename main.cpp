#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "obstacle.h"
#include "vehicle.h"
#include "window.h"

int main()
{
  sf::RenderWindow * window = create_window();
  Hedgehog hedgehog = create_hedgehog(window->getSize().x, window->getSize().y);
  std::vector<Vehicle> vehicles = create_vehicles(hedgehog.getSize(), window->getSize().x);
  std::vector<Obstacle> obstacles = create_obstacles(window->getSize().x, hedgehog.getSize());

  sf::Clock clock;
  sf::Font font;
  font.loadFromFile("arial.ttf");

  bool game_over_screen = false;
  bool winner_screen = false;

  while(window->isOpen())
  {
    sf::Event event;

    sf::Text text;
    text.setFont(font);
    text.setPosition(100,100);
    text.setColor(sf::Color::White);

    while(window->pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window->close();
          break;
        case sf::Event::KeyPressed:
          move(window, hedgehog, obstacles);
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

    for(auto &vehicle : vehicles)
    {
      if (are_colliding(vehicle, hedgehog))
      {
        game_over_screen = true;
      }
    }
    for(auto &vehicle : vehicles)
    {
      keep_vehicle_in_window(window, vehicle);
    }
    if(hedgehog.getPosition().y == 0)
    {
      winner_screen = true;
    }

    draw_on_window(window, hedgehog, vehicles, text, obstacles, game_over_screen, winner_screen);
  }
}
