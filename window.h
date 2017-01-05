#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

#include "hedgehog.h"
#include "obstacle.h"
#include "vehicle.h"

sf::RenderWindow * create_window(const int window_height = 630, const int window_width = 630);
void draw_on_window(sf::RenderWindow * window, Hedgehog hedgehog, std::vector<Vehicle> vehicles, std::vector<Obstacle> obstacles, bool game_over_screen, bool winner_screen);
void game_on_screen(sf::RenderWindow * window, std::vector<Obstacle> obstacles, std::vector<Vehicle> vehicles, Hedgehog hedgehog);
void game_over_screen(sf::RenderWindow * window);
void is_winner_screen(sf::RenderWindow * window);

#endif // WINDOW_H
