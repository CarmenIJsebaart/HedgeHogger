#include "game.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_hedgehog_moves_up_when_user_presses_up_arrow)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Up);
  const Hedgehog h_after = g.get_hedgehog();
  BOOST_CHECK(h_after.getPosition() != h_before.getPosition());
}

BOOST_AUTO_TEST_CASE(test_hedgehog_does_not_move_when_user_presses_down_arrow_at_start)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Down);
  const Hedgehog h_after = g.get_hedgehog();
  BOOST_CHECK(h_after.getPosition() == h_before.getPosition());
}

BOOST_AUTO_TEST_CASE(test_game_restart_moves_hedgehog_back)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Up);
  const Hedgehog h_after = g.get_hedgehog();
  assert(h_after.getPosition() != h_before.getPosition());
  g.restart();
  BOOST_CHECK(g.get_hedgehog().getPosition() == h_before.getPosition());
}

#pragma GCC diagnostic pop

