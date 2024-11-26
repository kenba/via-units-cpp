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
/// @file via_angle_python_bindings.cpp
/// @brief Contains the via::angle python interface
//////////////////////////////////////////////////////////////////////////////
// ensure numpy.h included before angle.hpp
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

  // SI Units

  // Python numpy binding for the Metres class
  PYBIND11_NUMPY_DTYPE(via::units::si::Metres<double>, v_);

  // Python bindings for the Metres class
  py::class_<via::units::si::Metres<double>>(m, "Metres")
      .def(py::init<double>())

      .def("v", &via::units::si::Metres<double>::v)
      .def("__repr__", &via::units::si::Metres<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self == py::self);

  // Non-SI Units

  // Python numpy binding for the NauticalMiles class
  PYBIND11_NUMPY_DTYPE(via::units::non_si::NauticalMiles<double>, v_);

  // Python bindings for the NauticalMiles class
  py::class_<via::units::non_si::NauticalMiles<double>>(m, "NauticalMiles")
      .def(py::init<double>())

      .def("v", &via::units::non_si::NauticalMiles<double>::v)
      .def("__repr__", &via::units::non_si::NauticalMiles<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self == py::self);

  // Python numpy binding for the Feet class
  PYBIND11_NUMPY_DTYPE(via::units::non_si::Feet<double>, v_);

  // Python bindings for the Feet class
  py::class_<via::units::non_si::Feet<double>>(m, "Feet")
      .def(py::init<double>())

      .def("v", &via::units::non_si::Feet<double>::v)
      .def("__repr__", &via::units::non_si::Feet<double>::python_repr)

      .def(py::self < py::self)
      .def(py::self == py::self);
}
