#include "game.h"

Game::Game()
  : hedgehog(sf::Vector2f(), 0.0, sf::Color::Black),
    obstacles{},
    vehicles{},
    window{create_window()},
    is_game_over{false},
    is_winner{false}

{
  hedgehog = create_hedgehog(window->getSize().x, window->getSize().y);
  obstacles = create_obstacles(window->getSize().x, hedgehog.getSize());
  vehicles = create_vehicles(hedgehog.getSize(), window->getSize().x);
}

void process_poll_events(
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  std::vector<Obstacle> obstacles,
  bool &is_game_over,
  bool &is_winner)
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
      {
        const std::pair<bool, bool> p = start_over(window, hedgehog, is_game_over, is_winner);
        is_game_over = p.first;
        is_winner = p.second;
        move(window, hedgehog, obstacles);
      }
      break;
    default:
      break;
    }
  }
}

void Game::run()
{
  sf::Clock clock;

  while(window->isOpen())
  {
    process_poll_events(window, hedgehog, obstacles, is_game_over, is_winner);

    const double update_time = 10; //milliseconds
    if(clock.getElapsedTime().asMilliseconds() >= update_time)
    {
      drive(vehicles);
      keep_vehicles_in_window(window, vehicles);
      clock.restart();
    }
    if(are_colliding(vehicles, hedgehog)) { is_game_over = true; }
    if(hedgehog.getPosition().y == 0) { is_winner = true; }

    draw_on_window(window, hedgehog, vehicles, obstacles, is_game_over, is_winner);
  }
}

std::pair<bool, bool> start_over(
  sf::RenderWindow * window,
  Hedgehog &hedgehog,
  bool is_game_over,
  bool is_winner)
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    //is_game_over = false;
    //is_winner = false;
    hedgehog.setPosition(
      sf::Vector2f(
        (window->getSize().x / 2) - hedgehog.getSize(),
         window->getSize().y - (hedgehog.getSize() * 2)));
    return std::make_pair(false, false);
  }
  return std::make_pair(is_game_over, is_winner);
}
