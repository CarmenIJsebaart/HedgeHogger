#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "obstacle.h"
#include "window.h"

class Game
{
public:
  Game();

  const Hedgehog& get_hedgehog() const noexcept { return hedgehog; }

  void press_key(
    const sf::Keyboard::Key k);
  void restart();
  void run();
  void tick();

private:

  sf::Clock clock;
  Hedgehog hedgehog;
  std::vector<Obstacle> obstacles;
  std::vector<Vehicle> vehicles;
  sf::RenderWindow * window;
  bool is_game_over;
  bool is_winner;

  void process_poll_events();
  void will_restart();
};

#endif // GAME_H
