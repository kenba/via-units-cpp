#pragma once

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
//////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief SI units.
//////////////////////////////////////////////////////////////////////////////
#include <concepts>
#include <ostream>
#include <string>

namespace via {
namespace units {
namespace si {

/// The Metres type for representing distance.
template <typename T>
  requires std::floating_point<T>
class Metres final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit Metres(const T value) noexcept : v_{value} {}

  /// Default constructor
  constexpr Metres() noexcept = default;

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering operator<=>(const Metres<T> &other) const {
    return v_ <=> other.v_;
  }

  /// The + operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator+(const Metres<T> &rhs) const noexcept -> Metres<T> {
    return Metres<T>(v_ + rhs.v_);
  }

  /// The += operator
  constexpr auto operator+=(const Metres<T> &rhs) noexcept -> Metres<T> & {
    v_ += rhs.v_;
    return *this;
  }

  /// Unary minus
  [[nodiscard("Pure Function")]]
  constexpr auto operator-() const noexcept -> Metres<T> {
    return Metres(T() - v_);
  }

  /// The - operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator-(const Metres<T> &rhs) const noexcept -> Metres<T> {
    return Metres<T>(v_ - rhs.v_);
  }

  /// The -= operator
  constexpr auto operator-=(const Metres<T> &rhs) noexcept -> Metres<T> & {
    v_ -= rhs.v_;
    return *this;
  }

  /// A Python representation of a Metres.
  /// I.e.: Metres(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "Metres(" + std::to_string(v_) + ")";
  }
}; // Metres

/// Metres equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const Metres<T> &lhs, const Metres<T> &rhs) noexcept
    -> bool {
  return lhs.v() == rhs.v();
}

/// Metres ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const Metres<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The MetresPerSecond type for representing speed.
template <typename T>
  requires std::floating_point<T>
class MetresPerSecond final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit MetresPerSecond(const T value) noexcept : v_{value} {}

  /// Default constructor
  constexpr MetresPerSecond() noexcept = default;

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering
  operator<=>(const MetresPerSecond<T> &other) const {
    return v_ <=> other.v_;
  }

  /// The + operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator+(const MetresPerSecond<T> &rhs) const noexcept
      -> MetresPerSecond<T> {
    return MetresPerSecond<T>(v_ + rhs.v_);
  }

  /// The += operator
  constexpr auto operator+=(const MetresPerSecond<T> &rhs) noexcept
      -> MetresPerSecond<T> & {
    v_ += rhs.v_;
    return *this;
  }

  /// Unary minus
  [[nodiscard("Pure Function")]]
  constexpr auto operator-() const noexcept -> MetresPerSecond<T> {
    return MetresPerSecond(T() - v_);
  }

  /// The - operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator-(const MetresPerSecond<T> &rhs) const noexcept
      -> MetresPerSecond<T> {
    return MetresPerSecond<T>(v_ - rhs.v_);
  }

  /// The -= operator
  constexpr auto operator-=(const MetresPerSecond<T> &rhs) noexcept
      -> MetresPerSecond<T> & {
    v_ -= rhs.v_;
    return *this;
  }

  /// A Python representation of a MetresPerSecond.
  /// I.e.: MetresPerSecond(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "MetresPerSecond(" + std::to_string(v_) + ")";
  }
}; // MetresPerSecond

/// MetresPerSecond equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const MetresPerSecond<T> &lhs,
                          const MetresPerSecond<T> &rhs) noexcept -> bool {
  return lhs.v() == rhs.v();
}

/// MetresPerSecond ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const MetresPerSecond<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The MetresPerSecondSquared type for representing acceleration.
template <typename T>
  requires std::floating_point<T>
class MetresPerSecondSquared final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit MetresPerSecondSquared(const T value) noexcept
      : v_{value} {}

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering
  operator<=>(const MetresPerSecondSquared<T> &other) const {
    return v_ <=> other.v_;
  }

  /// A Python representation of a MetresPerSecondSquared.
  /// I.e.: MetresPerSecondSquared(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "MetresPerSecondSquared(" + std::to_string(v_) + ")";
  }
}; // MetresPerSecondSquared

/// MetresPerSecondSquared equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const MetresPerSecondSquared<T> &lhs,
                          const MetresPerSecondSquared<T> &rhs) noexcept
    -> bool {
  return lhs.v() == rhs.v();
}

/// MetresPerSecondSquared ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const MetresPerSecondSquared<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The Kelvin type for representing temperature.
template <typename T>
  requires std::floating_point<T>
class Kelvin final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit Kelvin(const T value) noexcept : v_{value} {}

  /// Default constructor
  constexpr Kelvin() noexcept = default;

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering operator<=>(const Kelvin<T> &other) const {
    return v_ <=> other.v_;
  }

  /// The + operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator+(const Kelvin<T> &rhs) const noexcept -> Kelvin<T> {
    return Kelvin<T>(v_ + rhs.v_);
  }

  /// The += operator
  constexpr auto operator+=(const Kelvin<T> &rhs) noexcept -> Kelvin<T> & {
    v_ += rhs.v_;
    return *this;
  }

  /// Unary minus
  [[nodiscard("Pure Function")]]
  constexpr auto operator-() const noexcept -> Kelvin<T> {
    return Kelvin(T() - v_);
  }

  /// The - operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator-(const Kelvin<T> &rhs) const noexcept -> Kelvin<T> {
    return Kelvin<T>(v_ - rhs.v_);
  }

  /// The -= operator
  constexpr auto operator-=(const Kelvin<T> &rhs) noexcept -> Kelvin<T> & {
    v_ -= rhs.v_;
    return *this;
  }

  /// A Python representation of a Kelvin.
  /// I.e.: Kelvin(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "Kelvin(" + std::to_string(v_) + ")";
  }
}; // Kelvin

/// Kelvin equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const Kelvin<T> &lhs, const Kelvin<T> &rhs) noexcept
    -> bool {
  return lhs.v() == rhs.v();
}

/// Kelvin ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const Kelvin<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The Pascals type for representing pressure.
template <typename T>
  requires std::floating_point<T>
class Pascals final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit Pascals(const T value) noexcept : v_{value} {}

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering operator<=>(const Pascals<T> &other) const {
    return v_ <=> other.v_;
  }

  /// A Python representation of a Pascals.
  /// I.e.: Pascals(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "Pascals(" + std::to_string(v_) + ")";
  }
}; // Pascals

/// Pascals equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const Pascals<T> &lhs, const Pascals<T> &rhs) noexcept
    -> bool {
  return lhs.v() == rhs.v();
}

/// Pascals ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const Pascals<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The Kilograms type for representing mass.
template <typename T>
  requires std::floating_point<T>
class Kilograms final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit Kilograms(const T value) noexcept : v_{value} {}

  /// Default constructor
  constexpr Kilograms() noexcept = default;

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering operator<=>(const Kilograms<T> &other) const {
    return v_ <=> other.v_;
  }

  /// The + operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator+(const Kilograms<T> &rhs) const noexcept
      -> Kilograms<T> {
    return Kilograms<T>(v_ + rhs.v_);
  }

  /// The += operator
  constexpr auto operator+=(const Kilograms<T> &rhs) noexcept
      -> Kilograms<T> & {
    v_ += rhs.v_;
    return *this;
  }

  /// Unary minus
  [[nodiscard("Pure Function")]]
  constexpr auto operator-() const noexcept -> Kilograms<T> {
    return Kilograms(T() - v_);
  }

  /// The - operator
  [[nodiscard("Pure Function")]]
  constexpr auto operator-(const Kilograms<T> &rhs) const noexcept
      -> Kilograms<T> {
    return Kilograms<T>(v_ - rhs.v_);
  }

  /// The -= operator
  constexpr auto operator-=(const Kilograms<T> &rhs) noexcept
      -> Kilograms<T> & {
    v_ -= rhs.v_;
    return *this;
  }

  /// A Python representation of a Kilograms.
  /// I.e.: Kilograms(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "Kilograms(" + std::to_string(v_) + ")";
  }
}; // Kilograms

/// Kilograms equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const Kilograms<T> &lhs,
                          const Kilograms<T> &rhs) noexcept -> bool {
  return lhs.v() == rhs.v();
}

/// Kilograms ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const Kilograms<T> &a)
    -> std::ostream & {
  return os << a.v();
}

/// The KilogramsPerCubicMetre type for representing density.
template <typename T>
  requires std::floating_point<T>
class KilogramsPerCubicMetre final {
#ifdef PYBIND11_NUMPY_DTYPE
public:
#endif
  T v_;
#ifndef PYBIND11_NUMPY_DTYPE
public:
#endif
  /// Constructor
  constexpr explicit KilogramsPerCubicMetre(const T value) noexcept
      : v_{value} {}

  /// The accessor for v.
  [[nodiscard("Pure Function")]]
  constexpr auto v() const noexcept -> T {
    return v_;
  }

  /// The spaceship operator
  constexpr std::partial_ordering
  operator<=>(const KilogramsPerCubicMetre<T> &other) const {
    return v_ <=> other.v_;
  }

  /// A Python representation of a KilogramsPerCubicMetre.
  /// I.e.: KilogramsPerCubicMetre(v)
  /// @return a string in Python repr format.
  std::string python_repr() const {
    return "KilogramsPerCubicMetre(" + std::to_string(v_) + ")";
  }
}; // KilogramsPerCubicMetre

/// KilogramsPerCubicMetre equality operator
template <typename T>
  requires std::floating_point<T>
[[nodiscard("Pure Function")]]
constexpr auto operator==(const KilogramsPerCubicMetre<T> &lhs,
                          const KilogramsPerCubicMetre<T> &rhs) noexcept
    -> bool {
  return lhs.v() == rhs.v();
}

/// KilogramsPerCubicMetre ostream << operator
template <typename T>
  requires std::floating_point<T>
constexpr auto operator<<(std::ostream &os, const KilogramsPerCubicMetre<T> &a)
    -> std::ostream & {
  return os << a.v();
}

} // namespace si
} // namespace units
} // namespace via
