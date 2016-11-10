#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
  const int window_height = 600;
  const int window_width = 600;
  sf::RenderWindow window(sf::VideoMode(window_width, window_height), "HedgeHogger", sf::Style::Titlebar | sf::Style::Close);

  sf::CircleShape hedgehog;
  const int hedgehog_size = 15;
  hedgehog.setRadius(hedgehog_size);
  hedgehog.setFillColor(sf::Color::Red);
  int hedgehog_x_position = (window_width / 2) - hedgehog_size;
  int hedgehog_y_position = window_height - (hedgehog_size * 2);
  hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));

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
        case sf::Event::KeyPressed:
          if(hedgehog_x_position >= (2 * hedgehog_size))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
              hedgehog_x_position = hedgehog_x_position - (2 * hedgehog_size);
              hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));
            }
          }
          if(hedgehog_x_position <= (window_width - (4 * hedgehog_size)))
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
              hedgehog_x_position = hedgehog_x_position + (2 * hedgehog_size);
              hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));
            }
          }
          if(hedgehog_y_position >= hedgehog_size)
          {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
              hedgehog_y_position = hedgehog_y_position - (2 * hedgehog_size);
              hedgehog.setPosition(sf::Vector2f(hedgehog_x_position, hedgehog_y_position));
            }
          }
        default:
          break;
      }
    }

    window.clear();
    window.draw(hedgehog);
    window.display();
  }
}
