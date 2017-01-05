#include "window.h"

sf::RenderWindow * create_window(
  const int window_height,
  const int window_width)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_width, window_height),
             "HedgeHogger",
              sf::Style::Titlebar | sf::Style::Close);
}

void draw_on_window(
  sf::RenderWindow * window,
  Hedgehog hedgehog,
  std::vector<Vehicle> vehicles,
  std::vector<Obstacle> obstacles,
  bool is_game_over,
  bool is_winner)
{
  sf::Text text;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  text.setFont(font);
  text.setPosition(100,100);
  text.setColor(sf::Color::White);

  if(is_game_over == false && is_winner == false)
  {
    game_on_screen(window, obstacles, vehicles, hedgehog, text);
  }
  if(is_game_over == true)
  {
    game_over_screen(window, text);
  }
  if(is_winner == true)
  {
    is_winner_screen(window, text);
  }
}

void game_on_screen(
  sf::RenderWindow * window,
  std::vector<Obstacle> obstacles,
  std::vector<Vehicle> vehicles,
  Hedgehog hedgehog,
  sf::Text text)
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

void game_over_screen(sf::RenderWindow * window, sf::Text text)
{
  window->clear(sf::Color::Black);
  text.setString("Game Over");
  text.setCharacterSize(80);
  window->draw(text);
  window->display();
}

void is_winner_screen(sf::RenderWindow * window, sf::Text text)
{
  window->clear(sf::Color::Red);
  text.setString("Winner!");
  text.setCharacterSize(120);
  window->draw(text);
  window->display();
}
