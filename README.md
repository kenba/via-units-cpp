# via-units-cpp

Units for air navigation as defined in [International Civil Aviation Organization](https://icao.int/) (ICAO) [Annex 5](https://store.icao.int/en/annex-5-units-of-measurement-to-be-used-in-the-air-and-ground-services).

The library defines:

- the [SI](https://en.wikipedia.org/wiki/International_System_of_Units)
units used in the [International Standard Atmosphere](https://en.wikipedia.org/wiki/International_Standard_Atmosphere) (ISA),
- the non-SI units defined in `ICAO Annex 5` Table 3-3,
- and conversions between SI and non-SI units.

## Use

The C++ software has no dependencies.
The C++ tests use the [boost.test](https://www.boost.org/doc/libs/1_86_0/libs/test/doc/html/boost_test/intro.html)
library.

### C++

#### Installation

The library is header only, so the library `include` directory just needs to be added to the include path.
Alternatively, when using [cmake](https://cmake.org/) the environment variable `ViaUnits_DIR` just needs
to be set to the location of the `via-units-cpp` directory; `cmake` will add it to the include path.

Note: `CMakeLists.txt` is setup to install python by default, so `-DINSTALL_PYTHON=OFF`
must be passed to `cmake` when building for C++.

`cmake` can also be used to install the library to the relevant include directory on Linux/macOS.
In the `via-units-cpp` directory, run:

```bash
cmake -DINSTALL_PYTHON=OFF .
sudo make install
```

Note: it will be necessary to delete the `CMakeCache.txt` file created by
running `cmake` above, before running `cmake` on this library again.

#### Tests

The C++ tests can be built and run using `cmake` by running:

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DINSTALL_PYTHON=OFF -DCPP_UNIT_TESTS=ON <via-units-cpp directory>
make
make test
```

Note: `-DCMAKE_EXPORT_COMPILE_COMMANDS=1` creates a `compile_commands.json`
file which can be copied back into the `via-units-cpp` directory for
[clangd](https://clangd.llvm.org/) tools.

### Python

The library uses [pybind11](https://github.com/pybind/pybind11) to provide C++ Python bindings
and [scikit-build](https://pypi.org/project/scikit-build/) to build a python package using
[cmake](https://cmake.org/).

From the parent directory of `via-units-cpp`, run:

```bash
pip install ./via-units-cpp
```

In Python code import the software as `via_units`, e.g.:

```python
from via_units import Feet, Metres, NauticalMiles
```

See: [test_units.py](python/tests/test_units.py).

## License

`via-units-cpp` is provided under a MIT license, see [LICENSE](LICENSE).
