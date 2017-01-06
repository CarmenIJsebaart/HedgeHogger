#include "game.h"

Game::Game()
  : hedgehog(sf::Vector2f(), 0.0, sf::Color::Black, 0),
    obstacles{},
    vehicles{},
    window{create_window()},
    state{Gamestate::normal}
{
  hedgehog = create_hedgehog(window->getSize().x);
  obstacles = create_obstacles(window->getSize().x, hedgehog.get_size());
  vehicles = create_vehicles(hedgehog.get_size(), window->getSize().x);
}

void Game::press_key(
  const sf::Keyboard::Key k)
{
  if(k == sf::Keyboard::Down)
  {
    move_down(hedgehog, *window, obstacles);
  }
  else if(k == sf::Keyboard::Left)
  {
    move_left(hedgehog, obstacles);
  }
  else if(k == sf::Keyboard::Right)
  {
    move_right(hedgehog, *window, obstacles);
  }
  else if(k == sf::Keyboard::Up)
  {
    move_up(hedgehog, obstacles);
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    will_restart();
  }
}

void Game::process_poll_events()
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
        press_key(event.key.code);
      }
      break;
    default:
      break;
    }
  }
}

void Game::restart()
{
  hedgehog = create_hedgehog(window->getSize().x);
  state = Gamestate::normal;
}

void Game::run()
{
  clock.restart();
  while(window->isOpen())
  {
    tick();
  }
}

void Game::tick()
{
  process_poll_events();

  const double update_time = 10; //milliseconds
  if(clock.getElapsedTime().asMilliseconds() >= update_time)
  {
    drive(vehicles);
    keep_vehicles_in_window(*window, vehicles);
    clock.restart();
  }
  if(are_colliding(vehicles, hedgehog)) { state = Gamestate::game_over; }
  if(hedgehog.get_position().y == 0) { state = Gamestate::game_won; }

  draw_on_window(*window, hedgehog, vehicles, obstacles, state);
}

void Game::will_restart()
{
  if(state == Gamestate::game_over || state == Gamestate::game_won)
  {
    restart();
  }
}
