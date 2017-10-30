MESSAGE ("Running CMake on libdnf...")
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)


ADD_COMPILE_OPTIONS (-std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -fPIC)

set(CMAKE_MACOSX_RPATH 0) # to disable MAC OS warnings

PROJECT (libdnf)

if (NOT PYTHON_DESIRED)
    set (PYTHON_DESIRED "3")
endif()

find_package(PkgConfig)
SET (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
PKG_CHECK_MODULES(GLIB gio-unix-2.0>=2.46.0 REQUIRED)
INCLUDE_DIRECTORIES(${GLIB_INCLUDE_DIRS})

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
