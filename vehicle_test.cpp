#include "vehicle.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_vehicle_set_and_get_should_be_symmetrical)
{
  const sf::Color color(sf::Color::Green);
  const int length = 100;
  const sf::Vector2f any_position(3.14, 2.71);
  const float speed = 2.0;
  const int width = 30;
  const bool direction = true;
  const Vehicle v(any_position, length, width, color, speed, direction);
  BOOST_CHECK(v.getPosition() == any_position);
  BOOST_CHECK(v.getWidth() == width);
  BOOST_CHECK(v.getLength() == length);
  BOOST_CHECK(v.getColor() == color);
  BOOST_CHECK(v.getSpeed() == speed);
  BOOST_CHECK(v.getDirection() == direction);
}

#pragma GCC diagnostic pop



