#include "vehicle.h"
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <SFML/Graphics.hpp>

// Boost.Test does not play well with -Weffc++
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

BOOST_AUTO_TEST_CASE(test_vehicle_constuctor_arguments_should_be_gettable)
{
  const sf::Color color(sf::Color::Green);
  const int length = 100;
  const sf::Vector2f any_position(3.14, 2.71);
  const float speed = 2.0;
  const int width = 30;
  const bool direction = true;
  const Vehicle v(any_position, length, width, color, speed, direction);
  BOOST_CHECK(v.get_position() == any_position);
  BOOST_CHECK(v.get_width() == width);
  BOOST_CHECK(v.get_length() == length);
  BOOST_CHECK(v.get_color() == color);
  BOOST_CHECK(v.get_speed() == speed);
  BOOST_CHECK(v.get_direction() == direction);
}

Vehicle create_test_vehicle() noexcept
{
  return Vehicle(sf::Vector2f(201.12, 156.15), 105, 45, sf::Color::Yellow, 5, true);
}

BOOST_AUTO_TEST_CASE(test_vehicle_setter_and_getter_must_be_symmetrical)
{
  Vehicle v = create_test_vehicle();
  sf::Vector2f veh = v.get_position();
  veh.x += 1.0;
  veh.y += 1.0;
  v.set_position(veh);
  BOOST_CHECK(v.get_position() == veh);

  //Vehicle must be placed just outside window (on the left)
  set_vehicle_left(v);
  BOOST_CHECK(v.get_position().x == -v.get_length());

  //Vehicle must be placed just outside window (on the right)
  const int window_width = 100;
  set_vehicle_right(v, window_width);
  BOOST_CHECK(v.get_position().x == window_width);
}

BOOST_AUTO_TEST_CASE(test_vehicle_get_shape)
{
  const Vehicle v = create_test_vehicle();
  const sf::RectangleShape  s = get_shape(v);
  BOOST_CHECK(s.getFillColor() == v.get_color());
  BOOST_CHECK(s.getPosition() == v.get_position());
  BOOST_CHECK(s.getSize().x == v.get_length());
  BOOST_CHECK(s.getSize().y == v.get_width());
}

#pragma GCC diagnostic pop
