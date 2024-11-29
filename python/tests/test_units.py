#!/usr/bin/env python

# Copyright (c) 2024 Ken Barker
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
#  @file test_units
#  @brief Contains unit tests for the via units classes and constants.

import pytest
from via_units import Feet, Metres, NauticalMiles, \
    METRES_PER_FOOT, METRES_PER_NAUTICAL_MILE

def test_Metres():
    one = Metres(1.0)
    minus_one = Metres(-1.0)

    assert 1.0 == one.v()
    assert one == one
    assert minus_one < one
    assert minus_one <= one

    assert minus_one != one
    assert one > minus_one
    assert one >= minus_one

    assert "Metres(1.000000)" == repr(one)

def test_NauticalMiles():
    one = NauticalMiles(1.0)
    minus_one = NauticalMiles(-1.0)

    assert 1.0 == one.v()
    assert one == one
    assert minus_one < one
    assert minus_one <= one

    assert minus_one != one
    assert one > minus_one
    assert one >= minus_one

    assert "NauticalMiles(1.000000)" == repr(one)

def test_NauticalMiles_conversion():
    one_nm = NauticalMiles(1.0)

    metres = one_nm.to_metres()
    assert METRES_PER_NAUTICAL_MILE == metres.v()

    result = NauticalMiles(metres)
    assert 1.0 == result.v()

def test_Feet():
    one = Feet(1.0)
    minus_one = Feet(-1.0)

    assert 1.0 == one.v()
    assert one == one
    assert minus_one < one
    assert minus_one <= one

    assert minus_one != one
    assert one > minus_one
    assert one >= minus_one

    assert "Feet(1.000000)" == repr(one)

def test_Feet_conversion():
    one_nm = Feet(1.0)

    metres = one_nm.to_metres()
    assert METRES_PER_FOOT == metres.v()

    result = Feet(metres)
    assert 1.0 == result.v()

if __name__ == '__main__':
    pytest.main()
