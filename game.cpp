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
  obstacles = create_obstacles(window->getSize().x, hedgehog.get_size());
  vehicles = create_vehicles(hedgehog.get_size(), window->getSize().x);
}

void Game::press_key(
  const sf::Keyboard::Key k)
{
  if(k == sf::Keyboard::Down)
  {
    move_down(hedgehog, window, obstacles);
  }
  else if(k == sf::Keyboard::Left)
  {
    move_left(hedgehog, obstacles);
  }
  else if(k == sf::Keyboard::Right)
  {
    move_right(hedgehog, window, obstacles);
  }
  else if(k == sf::Keyboard::Up)
  {
    move_up(hedgehog, obstacles);
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
        will_restart();
        move(window, hedgehog, obstacles);
      }
      break;
    default:
      break;
    }
  }
}

void Game::will_restart()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    restart();
  }
}


void Game::restart()
{
  hedgehog = create_hedgehog(window->getSize().x, window->getSize().y);
  is_game_over = false;
  is_winner = false;
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
    keep_vehicles_in_window(window, vehicles);
    clock.restart();
  }
  if(are_colliding(vehicles, hedgehog)) { is_game_over = true; }
  if(hedgehog.get_position().y == 0) { is_winner = true; }

  draw_on_window(window, hedgehog, vehicles, obstacles, is_game_over, is_winner);
}
