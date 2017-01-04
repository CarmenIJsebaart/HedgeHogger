#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

/*
class Window
{
    int window_height;
    int window_width;
public:
    Window();

    int getHeight() const { return window_height; }
    int getWidth() const { return window_width; }
};
*/

sf::RenderWindow * create_window(const int window_height = 600, const int window_width = 600);

#endif // WINDOW_H

