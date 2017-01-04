#include "window.h"

sf::RenderWindow * create_window(const int window_height, const int window_width)
{
  return new sf::RenderWindow(
             sf::VideoMode(window_width, window_height),
                           "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);
}
