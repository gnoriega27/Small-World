# Boilerplate Project

This project is a boilerplate C++ project that includes documentation, unit tests, and an example makefile.

## Dependencies
* `cppunit`
    - Installable with `sudo apt install libcppunit-dev`
* `doxygen`
* `astyle`
* `graphviz`

## Documentation
* Run `make docs` to generate doxygen documentation. HTML documentation can be found in `doc/html/index.html`

## Unit tests
* Add test suites to `tests/` and add them to the test suite registry with `CPPUNIT_TEST_SUITE_REGISTRATION( <test name> );`
* Run unit tests with `make runtests`

## Astyle formatting
* Run `make format`. The astyle configuration may be found in `astyle.config`
