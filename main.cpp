#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  const int window_height = 600;
  const int window_width = 600;
  sf::RenderWindow window(sf::VideoMode(window_width, window_height), "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);

  while(window.isOpen())
  {
    sf::Event event;

    while(window.pollEvent(event))
    {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
        default:
          break;
      }
    }

    window.clear();
    window.display();
  }
}
