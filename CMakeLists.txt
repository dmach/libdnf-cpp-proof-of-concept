MESSAGE ("Running CMake on libdnf...")
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)


ADD_COMPILE_OPTIONS (-std=c++11 -Wall -Wextra -Wno-unused-parameter -fPIC)


PROJECT (libdnf)


if (${PYTHON_DESIRED} STREQUAL "2")
    message("Building for python2")
    FIND_PACKAGE (PythonInterp 2 REQUIRED)
    FIND_PACKAGE (PythonLibs 2 REQUIRED)
else()
    message("Building for python3")
    FIND_PACKAGE(PythonInterp 3 REQUIRED)
    FIND_PACKAGE(PythonLibs 3 REQUIRED)
endif()


INCLUDE_DIRECTORIES ("libdnf")
ADD_SUBDIRECTORY ("libdnf")


# configure tests
ENABLE_TESTING ()
ADD_SUBDIRECTORY ("tests/python")
