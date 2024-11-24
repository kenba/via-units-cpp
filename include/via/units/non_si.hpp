#pragma once

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
//////////////////////////////////////////////////////////////////////////////
#include "si.hpp"

namespace via {
namespace units {
namespace non_si {

/// The length of a Nautical Mile (NM) in metres (m).
/// Definition from ICAO Annex 5 Table 3-3.
template <typename T>
  requires std::floating_point<T>
constexpr T METRES_PER_NAUTICAL_MILE{static_cast<T>(1'852)};

/// The NauticalMiles type.
template <typename T>
  requires std::floating_point<T>
class NauticalMiles {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit NauticalMiles(const T value) noexcept : v_{value} {}

  /// Constructor from Metres
  constexpr explicit NauticalMiles(const si::Metres<T> value) noexcept
      : v_{value.v() / METRES_PER_NAUTICAL_MILE<T>} {}

  /// Convert to Metres
  constexpr auto to_metres() const noexcept -> si::Metres<T> {
    return si::Metres<T>(METRES_PER_NAUTICAL_MILE<T> * v_);
  }

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering
  operator<=>(const NauticalMiles<T> &other) const {
    return v_ <=> other.v_;
  }

  /// A Python representation of a NauticalMiles.
  /// I.e.: NauticalMiles(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "NauticalMiles(" + std::to_string(v_) + ")";
  }
}; // NauticalMiles

/// NauticalMiles equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const NauticalMiles<T> &lhs,
                          const NauticalMiles<T> &rhs) noexcept -> bool {
  return lhs.v() == rhs.v();
}

/// NauticalMiles ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const NauticalMiles<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The length of a foot (ft) in metres (m).
/// Definition from ICAO Annex 5 Table 3-3.
template <typename T>
  requires std::floating_point<T>
constexpr T METRES_PER_FOOT{static_cast<T>(0.3048L)};

/// The Feet type.
template <typename T>
  requires std::floating_point<T>
class Feet {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit Feet(const T value) noexcept : v_{value} {}

  /// Constructor from Metres
  constexpr explicit Feet(const si::Metres<T> value) noexcept
      : v_{value.v() / METRES_PER_FOOT<T>} {}

  /// Convert to Metres
  constexpr auto to_metres() const noexcept -> si::Metres<T> {
    return si::Metres<T>(METRES_PER_FOOT<T> * v_);
  }

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering operator<=>(const Feet<T> &other) const {
    return v_ <=> other.v_;
  }

  /// A Python representation of a Feet.
  /// I.e.: Feet(v)
  /// @return a string in Python repr format.
  std::string python_repr() const { return "Feet(" + std::to_string(v_) + ")"; }
}; // Feet

/// Feet equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const Feet<T> &lhs, const Feet<T> &rhs) noexcept
    -> bool {
  return lhs.v() == rhs.v();
}

/// Feet ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const Feet<T> &a)
    -> std::ostream & {
  return os << a.v();
}

} // namespace non_si
} // namespace units
} // namespace via
