#include "window.h"
#include <cmath>
#include <boost/test/unit_test.hpp>
#include <memory>
#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_draw_on_window)
{
  const int window_size{630};
  std::unique_ptr<sf::RenderWindow> window(create_window(window_size));
  const Hedgehog hedgehog = create_hedgehog(window_size);
  const std::vector<Vehicle> vehicles = create_vehicles(hedgehog.get_size(), window_size);
  const std::vector<Obstacle> obstacles = create_obstacles(window_size, hedgehog.get_size());
  //Default state
  {
    const Gamestate state = Gamestate::normal;
    BOOST_CHECK_NO_THROW(draw_on_window(*window, hedgehog, vehicles, obstacles, state));
  }
  //Game over state
  {
    const Gamestate state = Gamestate::game_over;
    BOOST_CHECK_NO_THROW(draw_on_window(*window, hedgehog, vehicles, obstacles, state));
  }
  //Game won state
  {
    const Gamestate state = Gamestate::game_won;
    BOOST_CHECK_NO_THROW(draw_on_window(*window, hedgehog, vehicles, obstacles, state));
  }
}

#pragma GCC diagnostic pop

