#include "window.h"

sf::RenderWindow * create_window(
  const int window_size)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_size, window_size),
             "HedgeHogger",
              sf::Style::Titlebar | sf::Style::Close);
}

void draw_on_window(
  sf::RenderWindow &window,
  const Hedgehog &hedgehog,
  const std::vector<Vehicle> &vehicles,
  const std::vector<Obstacle> &obstacles,
  const Gamestate &state)
{
  if(state == Gamestate::normal)
  {
    game_on_screen(window, obstacles, vehicles, hedgehog);
  }
  if(state == Gamestate::game_over)
  {
    game_over_screen(window);
  }
  if(state == Gamestate::game_won)
  {
    is_winner_screen(window);
  }
}

void game_on_screen(
  sf::RenderWindow &window,
  const std::vector<Obstacle> &obstacles,
  const std::vector<Vehicle> &vehicles,
  const Hedgehog &hedgehog)
{
  window.clear();
  for(auto &obstacle : obstacles)
  {
    window.draw(get_shape(obstacle));
  }
  window.draw(get_shape(hedgehog));
  for(auto &vehicle : vehicles)
  {
    window.draw(get_shape(vehicle));
  }
  window.display();
}

void game_over_screen(
  sf::RenderWindow &window)
{
  sf::Text text;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  text.setFont(font);
  text.setPosition(100,100);
  text.setColor(sf::Color::White);

  window.clear(sf::Color::Black);
  text.setString("Game Over");
  text.setCharacterSize(80);
  window.draw(text);
  window.display();
}

void is_winner_screen(
  sf::RenderWindow &window)
{
  sf::Text text;
  sf::Font font;
  font.loadFromFile("arial.ttf");
  text.setFont(font);
  text.setPosition(100,100);
  text.setColor(sf::Color::White);

  window.clear(sf::Color::Red);
  text.setString("Winner!");
  text.setCharacterSize(120);
  window.draw(text);
  window.display();
}
