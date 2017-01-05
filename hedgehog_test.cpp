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
  const Hedgehog h(any_position, size, color);
  BOOST_CHECK(h.getPosition() == any_position);
  BOOST_CHECK_EQUAL(h.getSize(), size);
  BOOST_CHECK(h.getColor() == color);
}

Hedgehog create_test_hedgehog() noexcept
{
  return Hedgehog(
    sf::Vector2f(3.14, 2.71),
    123.456,
    sf::Color(255, 128, 0)
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
  sf::Vector2f p = h.getPosition();
  p.x += 1.0;
  p.y += 1.0;
  h.setPosition(p);
  BOOST_CHECK_EQUAL(h.getPosition(), p);
}

#pragma GCC diagnostic pop


