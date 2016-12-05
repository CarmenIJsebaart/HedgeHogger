#include "hedgehog.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_hedgehog_set_and_get_should_be_symmetrical)
{
  const sf::Vector2f any_position(3.14, 2.71);
  const float size(123.456);
  const sf::Color color(255, 128, 0);
  const Hedgehog h(any_position, size, color);
  BOOST_CHECK(h.getPosition() == any_position);
  BOOST_CHECK_EQUAL(h.getSize(), size);
  BOOST_CHECK(h.getColor() == color);
}

#pragma GCC diagnostic pop


