#include "obstacle.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_obstacle_set_and_get_should_be_symmetrical)
{
  const sf::Vector2f position(102.12, 15.23);
  const int length = 12;
  const int width = 125;
  const sf::Color color = sf::Color::Blue;
  Obstacle obstacle(position, length, width, color);
  BOOST_CHECK(obstacle.get_color() == color);
  BOOST_CHECK(obstacle.get_length() == length);
  BOOST_CHECK(obstacle.get_position() == position);
  BOOST_CHECK(obstacle.get_width() == width);
}

BOOST_AUTO_TEST_CASE(test_create_obstacles_use)
{
  const std::vector<Obstacle> obstacles = create_obstacles(630, 15);
  BOOST_CHECK_EQUAL(obstacles.size(), 3);
}

BOOST_AUTO_TEST_CASE(test_create_obstacles_abuse)
{
  //Screen too small
  BOOST_CHECK_THROW(create_obstacles(10, 20), std::invalid_argument);

  //Obstacles don't fit
  BOOST_CHECK_THROW(create_obstacles(630, 19), std::invalid_argument);

  //Sizes cannot be zero
  BOOST_CHECK_THROW(create_obstacles(0, 0), std::invalid_argument);

  //Sizes cannot be negative
  BOOST_CHECK_THROW(create_obstacles(-630, -20), std::invalid_argument);
}

#pragma GCC diagnostic pop
