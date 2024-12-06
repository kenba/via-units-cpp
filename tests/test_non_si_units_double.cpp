//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Ken Barker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
/// @file
/// @brief Contains tests for the via::units::non_si namespace.
//////////////////////////////////////////////////////////////////////////////
#include "via/units/non_si.hpp"
#include <boost/test/tools/old/interface.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>

using namespace via::units::non_si;

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(Test_non_si_units_double)

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_NauticalMiles_traits) {
  const auto one{NauticalMiles<double>(1)};
  const auto minus_one{NauticalMiles<double>(-1)};

  BOOST_CHECK_EQUAL(one, one);
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("NauticalMiles(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_NauticalMiles_conversion) {
  const auto one_nm{NauticalMiles<double>(1)};

  const auto metres{one_nm.to_metres()};
  BOOST_CHECK_EQUAL(METRES_PER_NAUTICAL_MILE<double>, metres.v());

  const auto result{NauticalMiles<double>(metres)};
  BOOST_CHECK_EQUAL(1, result.v());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Feet_traits) {
  const auto one{Feet<double>(1)};
  const auto minus_one{Feet<double>(-1)};

  BOOST_CHECK_EQUAL(one, one);
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("Feet(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Feet_conversion) {
  const auto one_nm{Feet<double>(1)};

  const auto metres{one_nm.to_metres()};
  BOOST_CHECK_EQUAL(METRES_PER_FOOT<double>, metres.v());

  const auto result{Feet<double>(metres)};
  BOOST_CHECK_EQUAL(1, result.v());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Knots_traits) {
  const auto one{Knots<double>(1)};
  const auto minus_one{Knots<double>(-1)};

  BOOST_CHECK_EQUAL(one, one);
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("Knots(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Knots_conversion) {
  const auto one_kt{Knots<double>(1)};

  const auto metres_per_second{one_kt.to_metres_per_second()};
  BOOST_CHECK_EQUAL(METRES_PER_SECOND_TO_KNOTS<double>, metres_per_second.v());
  BOOST_CHECK_CLOSE(0.514'444, metres_per_second.v(), 1e-4);

  const auto result{Knots<double>(metres_per_second)};
  BOOST_CHECK_EQUAL(1, result.v());
}
//////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
//////////////////////////////////////////////////////////////////////////////
