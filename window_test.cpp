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
    bool is_game_over{false};
    bool is_winner{false};
    BOOST_CHECK_NO_THROW(draw_on_window(*window, hedgehog, vehicles, obstacles, is_game_over, is_winner));
  }
  //Game over state
  {
    bool is_game_over{true};
    bool is_winner{false};
    BOOST_CHECK_NO_THROW(draw_on_window(*window, hedgehog, vehicles, obstacles, is_game_over, is_winner));
  }
  //Game won state
  {
    bool is_game_over{false};
    bool is_winner{true};
    BOOST_CHECK_NO_THROW(draw_on_window(*window, hedgehog, vehicles, obstacles, is_game_over, is_winner));
  }
  //Cannot have both game over and winner
  /*
  {
    bool is_game_over{true};
    bool is_winner{true};
    BOOST_CHECK_THROW(
      draw_on_window(*window, hedgehog, vehicles, obstacles, is_game_over, is_winner),
      std::invalid_argument);
  }
  */
}

#pragma GCC diagnostic pop

