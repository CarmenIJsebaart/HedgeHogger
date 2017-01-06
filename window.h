#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "hedgehog.h"
#include "obstacle.h"
#include "vehicle.h"

sf::RenderWindow * create_window(
  const int window_size = 630);
void draw_on_window(sf::RenderWindow &window,
  const Hedgehog &hedgehog,
  const std::vector<Vehicle> &vehicles,
  const std::vector<Obstacle> &obstacles, const Gamestate &state);
void game_on_screen(sf::RenderWindow &window,
  const std::vector<Obstacle> &obstacles,
  const std::vector<Vehicle> &vehicles,
  const Hedgehog &hedgehog);
void game_over_screen(
  sf::RenderWindow &window);
void is_winner_screen(
  sf::RenderWindow &window);

#endif // WINDOW_H
