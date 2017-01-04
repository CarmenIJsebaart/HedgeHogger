#include "window.h"

sf::RenderWindow * create_window(const int window_height, const int window_width)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_width, window_height),
                           "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);
}

void draw_on_window(sf::RenderWindow *window, Hedgehog hedgehog, std::vector<Vehicle> vehicles,
                    sf::Text text, std::vector<Obstacle> obstacles)
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
