#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "obstacle.h"
#include "window.h"

class Game
{
  Hedgehog hedgehog;
  std::vector<Obstacle> obstacles;
  std::vector<Vehicle> vehicles;
  sf::RenderWindow * window;
  bool is_game_over;
  bool is_winner;
public:
  Game();

  void run();
};




void process_poll_events(
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles,
  bool &is_game_over,
  bool &is_winner);
std::pair<bool, bool> start_over(
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  bool is_game_over,
  bool is_winner);

#endif // GAME_H
