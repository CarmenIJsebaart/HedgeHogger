#ifndef GAME_H
#define GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "hedgehog.h"
#include "obstacle.h"
#include "window.h"
#include "gamestate.h"

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
  std::unique_ptr<sf::RenderWindow> window;
  Gamestate state;

  void process_poll_events();
  void will_restart();
};

#endif // GAME_H
