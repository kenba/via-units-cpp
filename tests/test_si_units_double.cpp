//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024-2025 Ken Barker
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
/// @brief Contains tests for the via::units::si namespace.
//////////////////////////////////////////////////////////////////////////////
#include "via/units/si.hpp"
#include <boost/test/unit_test.hpp>
#include <sstream>

using namespace via::units::si;

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(Test_si_units_double)

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Metres_traits) {
  const auto zero{Metres<double>()};
  BOOST_CHECK_EQUAL(0.0, zero.v());
  const auto one{Metres<double>(1)};
  BOOST_CHECK_EQUAL(one, one);
  const auto minus_one{Metres<double>(-1)};
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);
  BOOST_CHECK_EQUAL(minus_one, -one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  const auto two{Metres<double>(2)};
  BOOST_CHECK_EQUAL(two, one + one);
  BOOST_CHECK_EQUAL(one, two - one);

  auto one_clone{one};
  BOOST_CHECK_EQUAL(minus_one, one_clone -= two);
  BOOST_CHECK_EQUAL(one, one_clone += two);

  BOOST_CHECK_EQUAL("Metres(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_MetresPerSecond_traits) {
  const auto zero{MetresPerSecond<double>()};
  BOOST_CHECK_EQUAL(0.0, zero.v());
  const auto one{MetresPerSecond<double>(1)};
  BOOST_CHECK_EQUAL(one, one);
  const auto minus_one{MetresPerSecond<double>(-1)};
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);
  BOOST_CHECK_EQUAL(minus_one, -one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  const auto two{MetresPerSecond<double>(2)};
  BOOST_CHECK_EQUAL(two, one + one);
  BOOST_CHECK_EQUAL(one, two - one);

  auto one_clone{one};
  BOOST_CHECK_EQUAL(minus_one, one_clone -= two);
  BOOST_CHECK_EQUAL(one, one_clone += two);

  BOOST_CHECK_EQUAL("MetresPerSecond(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_MetresPerSecondSquared_traits) {
  const auto one{MetresPerSecondSquared<double>(1)};
  const auto minus_one{MetresPerSecondSquared<double>(-1)};

  BOOST_CHECK_EQUAL(one, one);
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("MetresPerSecondSquared(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Kelvin_traits) {
  const auto zero{Kelvin<double>()};
  BOOST_CHECK_EQUAL(0.0, zero.v());
  const auto one{Kelvin<double>(1)};
  BOOST_CHECK_EQUAL(one, one);
  const auto minus_one{Kelvin<double>(-1)};
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);
  BOOST_CHECK_EQUAL(minus_one, -one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  const auto two{Kelvin<double>(2)};
  BOOST_CHECK_EQUAL(two, one + one);
  BOOST_CHECK_EQUAL(one, two - one);

  auto one_clone{one};
  BOOST_CHECK_EQUAL(minus_one, one_clone -= two);
  BOOST_CHECK_EQUAL(one, one_clone += two);

  BOOST_CHECK_EQUAL("Kelvin(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Pascals_traits) {
  const auto one{Pascals<double>(1)};
  const auto minus_one{Pascals<double>(-1)};

  BOOST_CHECK_EQUAL(one, one);
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("Pascals(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_Kilograms_traits) {
  const auto zero{Kilograms<double>()};
  BOOST_CHECK_EQUAL(0.0, zero.v());
  const auto one{Kilograms<double>(1)};
  BOOST_CHECK_EQUAL(one, one);
  const auto minus_one{Kilograms<double>(-1)};
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);
  BOOST_CHECK_EQUAL(minus_one, -one);

  const auto two{Kilograms<double>(2)};
  BOOST_CHECK_EQUAL(two, one + one);
  BOOST_CHECK_EQUAL(one, two - one);

  auto one_clone{one};
  BOOST_CHECK_EQUAL(minus_one, one_clone -= two);
  BOOST_CHECK_EQUAL(one, one_clone += two);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("Kilograms(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(test_KilogramsPerCubicMetre_traits) {
  const auto one{KilogramsPerCubicMetre<double>(1)};
  const auto minus_one{KilogramsPerCubicMetre<double>(-1)};

  BOOST_CHECK_EQUAL(one, one);
  BOOST_CHECK(minus_one < one);
  BOOST_CHECK(minus_one <= one);

  BOOST_CHECK(minus_one != one);
  BOOST_CHECK(one > minus_one);
  BOOST_CHECK(one >= minus_one);

  BOOST_CHECK_EQUAL("KilogramsPerCubicMetre(1.000000)", one.python_repr());

  std::stringstream stream;
  stream << minus_one;
  BOOST_CHECK_EQUAL("-1", stream.str());
}
//////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
//////////////////////////////////////////////////////////////////////////////
