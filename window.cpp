#include "window.h"

/*
Window::Window()
  : window_height{600},
    window_width{600}
{
}
*/

sf::RenderWindow * create_window(const int window_height, const int window_width)
{
  return new sf::RenderWindow(
              sf::VideoMode(window_width, window_height),
                          "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);
}
