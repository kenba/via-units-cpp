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
/// @file via_units_python_bindings.cpp
/// @brief Contains the via::units python interface
//////////////////////////////////////////////////////////////////////////////
// ensure numpy.h included before units.hpp
// clang-format off
#include <pybind11/numpy.h>
#include "via/units.hpp"
// clang-format on
#include <pybind11/operators.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(via_units, m) {
  try {
    py::module::import("numpy");
  } catch (...) {
    return;
  }

  // Python bindings for constants
  m.attr("METRES_PER_NAUTICAL_MILE") =
      via::units::non_si::METRES_PER_NAUTICAL_MILE<double>;
  m.attr("METRES_PER_FOOT") = via::units::non_si::METRES_PER_FOOT<double>;
  m.attr("METRES_PER_SECOND_TO_KNOTS") =
      via::units::non_si::METRES_PER_SECOND_TO_KNOTS<double>;

  // SI Units

  // Python numpy binding for the Metres class
  PYBIND11_NUMPY_DTYPE(via::units::si::Metres<double>, v_);

  // Python bindings for the Metres class
  py::class_<via::units::si::Metres<double>>(m, "Metres")
      .def(py::init<>())
      .def(py::init<double>())

      .def("v", &via::units::si::Metres<double>::v)
      .def("__repr__", &via::units::si::Metres<double>::python_repr)

      .def(py::self + py::self)
      .def(py::self += py::self)
      .def(-py::self)
      .def(py::self - py::self)
      .def(py::self -= py::self)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the MetresPerSecond class
  PYBIND11_NUMPY_DTYPE(via::units::si::MetresPerSecond<double>, v_);

  // Python bindings for the MetresPerSecond class
  py::class_<via::units::si::MetresPerSecond<double>>(m, "MetresPerSecond")
      .def(py::init<double>())

      .def("v", &via::units::si::MetresPerSecond<double>::v)
      .def("__repr__", &via::units::si::MetresPerSecond<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the MetresPerSecondSquared class
  PYBIND11_NUMPY_DTYPE(via::units::si::MetresPerSecondSquared<double>, v_);

  // Python bindings for the MetresPerSecondSquared class
  py::class_<via::units::si::MetresPerSecondSquared<double>>(
      m, "MetresPerSecondSquared")
      .def(py::init<double>())

      .def("v", &via::units::si::MetresPerSecondSquared<double>::v)
      .def("__repr__",
           &via::units::si::MetresPerSecondSquared<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the Kelvin class
  PYBIND11_NUMPY_DTYPE(via::units::si::Kelvin<double>, v_);

  // Python bindings for the Kelvin class
  py::class_<via::units::si::Kelvin<double>>(m, "Kelvin")
      .def(py::init<double>())

      .def("v", &via::units::si::Kelvin<double>::v)
      .def("__repr__", &via::units::si::Kelvin<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the Pascals class
  PYBIND11_NUMPY_DTYPE(via::units::si::Pascals<double>, v_);

  // Python bindings for the Pascals class
  py::class_<via::units::si::Pascals<double>>(m, "Pascals")
      .def(py::init<double>())

      .def("v", &via::units::si::Pascals<double>::v)
      .def("__repr__", &via::units::si::Pascals<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the Kilograms class
  PYBIND11_NUMPY_DTYPE(via::units::si::Kilograms<double>, v_);

  // Python bindings for the Kilograms class
  py::class_<via::units::si::Kilograms<double>>(m, "Kilograms")
      .def(py::init<double>())

      .def("v", &via::units::si::Kilograms<double>::v)
      .def("__repr__", &via::units::si::Kilograms<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the KilogramsPerCubicMetre class
  PYBIND11_NUMPY_DTYPE(via::units::si::KilogramsPerCubicMetre<double>, v_);

  // Python bindings for the KilogramsPerCubicMetre class
  py::class_<via::units::si::KilogramsPerCubicMetre<double>>(
      m, "KilogramsPerCubicMetre")
      .def(py::init<double>())

      .def("v", &via::units::si::KilogramsPerCubicMetre<double>::v)
      .def("__repr__",
           &via::units::si::KilogramsPerCubicMetre<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Non-SI Units

  // Python numpy binding for the NauticalMiles class
  PYBIND11_NUMPY_DTYPE(via::units::non_si::NauticalMiles<double>, v_);

  // Python bindings for the NauticalMiles class
  py::class_<via::units::non_si::NauticalMiles<double>>(m, "NauticalMiles")
      .def(py::init<double>())
      .def(py::init<via::units::si::Metres<double>>())

      .def("to_metres", &via::units::non_si::NauticalMiles<double>::to_metres)
      .def("v", &via::units::non_si::NauticalMiles<double>::v)
      .def("__repr__", &via::units::non_si::NauticalMiles<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the Feet class
  PYBIND11_NUMPY_DTYPE(via::units::non_si::Feet<double>, v_);

  // Python bindings for the Feet class
  py::class_<via::units::non_si::Feet<double>>(m, "Feet")
      .def(py::init<double>())
      .def(py::init<via::units::si::Metres<double>>())

      .def("to_metres", &via::units::non_si::Feet<double>::to_metres)
      .def("v", &via::units::non_si::Feet<double>::v)
      .def("__repr__", &via::units::non_si::Feet<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);

  // Python numpy binding for the Knots class
  PYBIND11_NUMPY_DTYPE(via::units::non_si::Knots<double>, v_);

  // Python bindings for the Knots class
  py::class_<via::units::non_si::Knots<double>>(m, "Knots")
      .def(py::init<double>())
      .def(py::init<via::units::si::MetresPerSecond<double>>())

      .def("to_metres",
           &via::units::non_si::Knots<double>::to_metres_per_second)
      .def("v", &via::units::non_si::Knots<double>::v)
      .def("__repr__", &via::units::non_si::Knots<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self <= py::self)
      .def(py::self > py::self)
      .def(py::self >= py::self)
      .def(py::self == py::self);
}
