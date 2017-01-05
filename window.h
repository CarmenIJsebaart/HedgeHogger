#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "obstacle.h"
#include "vehicle.h"

sf::RenderWindow * create_window(const int window_height = 630, const int window_width = 630);
void draw_on_window(sf::RenderWindow * window, Hedgehog hedgehog, std::vector<Vehicle> vehicles,
                    sf::Text text, std::vector<Obstacle> obstacles, bool game_over_screen, bool winner_screen);

#endif // WINDOW_H
