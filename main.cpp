#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "obstacle.h"
#include "vehicle.h"
#include "window.h"

void process_poll_events(
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles);



int main()
{
  sf::RenderWindow * window = create_window();
  Hedgehog hedgehog = create_hedgehog(window->getSize().x, window->getSize().y);
  std::vector<Vehicle> vehicles = create_vehicles(hedgehog.getSize(), window->getSize().x);
  std::vector<Obstacle> obstacles = create_obstacles(window->getSize().x, hedgehog.getSize());

  sf::Clock clock;

  bool game_over_screen = false;
  bool winner_screen = false;

  while(window->isOpen())
  {
    process_poll_events(window, hedgehog, obstacles);

    const double update_time = 10; //milliseconds
    if(clock.getElapsedTime().asMilliseconds() >= update_time)
    {
      drive(vehicles);
      keep_vehicles_in_window(window, vehicles);
      clock.restart();
    }
    if(are_colliding(vehicles, hedgehog)) { game_over_screen = true; }
    if(hedgehog.getPosition().y == 0) { winner_screen = true; }

    draw_on_window(window, hedgehog, vehicles, obstacles, game_over_screen, winner_screen);
  }
}

void process_poll_events(
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles)
{
  sf::Event event;
  while(window->pollEvent(event))
  {
    switch(event.type) //!OCLINT I perhaps want to extend this in the future
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
}
