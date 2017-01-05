#include "game.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

int f(const int i)
{
  if (i == 42) throw std::invalid_argument("Cansroigheh");
  return i * 2;
}

BOOST_AUTO_TEST_CASE(test_mathematics_is_correct)
{
  BOOST_CHECK(1 + 1 == 2);

  const double a{3.14};
  const double b{3.1415};
  BOOST_CHECK(a == a);
  BOOST_CHECK_EQUAL(a, a);
  BOOST_CHECK_CLOSE(a, b, 0.1);
  BOOST_CHECK_NO_THROW(f(3));

  BOOST_CHECK_THROW(f(42), std::invalid_argument);

}

BOOST_AUTO_TEST_CASE(test_game)
{
  //Cannot be tested yet
}

#pragma GCC diagnostic pop

