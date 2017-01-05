#include "window.h"

sf::RenderWindow * create_window(
  const int window_height,
  const int window_width)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_width, window_height),
                           "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);
}

void draw_on_window(
  sf::RenderWindow * window,
  Hedgehog hedgehog,
  std::vector<Vehicle> vehicles,
  sf::Text text,
  std::vector<Obstacle> obstacles,
  bool game_over_screen,
  bool winner_screen)
{
  if(game_over_screen == false && winner_screen == false)
  {
    window->clear();
    for(auto &obstacle : obstacles)
    {
      window->draw(obstacle.getShape());
    }
    window->draw(hedgehog.getShape());
    for(auto &vehicle : vehicles)
    {
      window->draw(vehicle.getShape());
    }
    window->draw(text);
    window->display();
  }
  if(game_over_screen == true)
  {
    window->clear(sf::Color::Black);
    text.setString("Game Over");
    text.setCharacterSize(80);
    window->draw(text);
    window->display();
  }
  if(winner_screen == true)
  {
    window->clear(sf::Color::Red);
    text.setString("Winner!");
    text.setCharacterSize(120);
    window->draw(text);
    window->display();
  }
}
