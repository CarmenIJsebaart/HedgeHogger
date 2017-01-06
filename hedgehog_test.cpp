#include "hedgehog.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_hedgehog_constuctor_arguments_should_be_gettable)
{
  const sf::Vector2f any_position(3.14, 2.71);
  const float size(123.456);
  const sf::Color color(255, 128, 0);
  const int window_size = 485;
  const Hedgehog h(any_position, size, color, window_size);
  BOOST_CHECK(h.get_position() == any_position);
  BOOST_CHECK_EQUAL(h.get_size(), size);
  BOOST_CHECK(h.get_color() == color);
}

Hedgehog create_test_hedgehog() noexcept
{
  return Hedgehog(
    sf::Vector2f(3.14, 2.71),
    123.456,
    sf::Color(255, 128, 0),
    485
  );
}

namespace sf {
    std::ostream& operator<<(std::ostream& os, const sf::Vector2f& p)
    {
      os << "(" << p.x << "," << p.y << ")";
      return os;
    }
}

BOOST_AUTO_TEST_CASE(test_hedgehog_setter_and_getter_must_be_symmetrical)
{
  Hedgehog h = create_test_hedgehog();
  sf::Vector2f p = h.get_position();
  p.x += 1.0;
  p.y += 1.0;
  h.set_position(p);
  BOOST_CHECK_EQUAL(h.get_position(), p);
}

BOOST_AUTO_TEST_CASE(test_hedgehog_out_of_screen)
{
  Hedgehog h = create_test_hedgehog();

  //Hedgehog should not be out of screen (left)
  BOOST_CHECK_NO_THROW(h.set_position(sf::Vector2f(0, 0)));
  BOOST_CHECK_THROW   (h.set_position(sf::Vector2f(-1, 0)), std::invalid_argument);
  //Hedgehog should not be out of screen (top)
  BOOST_CHECK_THROW   (h.set_position(sf::Vector2f(0, -1)), std::invalid_argument);

  //Hedgehog should not be out of screen (right)
  BOOST_CHECK_NO_THROW(
    h.set_position(sf::Vector2f(h.get_window_size() - 2 * h.get_size() + 0, 10)));
  BOOST_CHECK_THROW(
    h.set_position(sf::Vector2f(h.get_window_size() - 2 * h.get_size() + 1, 10)), std::invalid_argument);

  //Hedgehog should not be out of screen (bottom)
  BOOST_CHECK_NO_THROW(
    h.set_position(sf::Vector2f(10, h.get_window_size() - 2 * h.get_size() + 0)));
  BOOST_CHECK_THROW(
    h.set_position(sf::Vector2f(10, h.get_window_size() - 2 * h.get_size() + 1)), std::invalid_argument);
}

#pragma GCC diagnostic pop


