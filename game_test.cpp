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
  BOOST_CHECK(h_after.get_position() != h_before.get_position());
}

BOOST_AUTO_TEST_CASE(test_hedgehog_moves_down_when_user_presses_down_arrow)
{
  Game g;
  g.press_key(sf::Keyboard::Up);
  g.press_key(sf::Keyboard::Up);
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Down);
  const Hedgehog h_after_down = g.get_hedgehog();
  BOOST_CHECK(h_after_down.get_position().y > h_before.get_position().y);
  BOOST_CHECK(h_after_down.get_position().x == h_before.get_position().x);
}

BOOST_AUTO_TEST_CASE(test_hedgehog_moves_right_when_user_presses_right_arrow)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Right);
  const Hedgehog h_after = g.get_hedgehog();
  BOOST_CHECK(h_after.get_position().x > h_before.get_position().x);
  BOOST_CHECK(h_after.get_position().y == h_before.get_position().y);
}

BOOST_AUTO_TEST_CASE(test_hedgehog_moves_left_when_user_presses_left_arrow)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Left);
  const Hedgehog h_after = g.get_hedgehog();
  BOOST_CHECK(h_after.get_position().x < h_before.get_position().x);
  BOOST_CHECK(h_after.get_position().y == h_before.get_position().y);
}

BOOST_AUTO_TEST_CASE(test_hedgehog_does_not_move_when_user_presses_down_arrow_at_start)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Down);
  const Hedgehog h_after = g.get_hedgehog();
  BOOST_CHECK(h_after.get_position() == h_before.get_position());
}

BOOST_AUTO_TEST_CASE(test_game_restart_moves_hedgehog_back)
{
  Game g;
  const Hedgehog h_before = g.get_hedgehog();
  g.press_key(sf::Keyboard::Up);
  const Hedgehog h_after = g.get_hedgehog();
  assert(h_after.get_position() != h_before.get_position());
  g.restart();
  BOOST_CHECK(g.get_hedgehog().get_position() == h_before.get_position());
}

#pragma GCC diagnostic pop

