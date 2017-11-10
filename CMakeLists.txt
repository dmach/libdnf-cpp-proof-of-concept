PROJECT (libdnf)

MESSAGE ("Running CMake on libdnf...")
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -Wall -Wextra -Werror -Wno-unused-parameter -fPIC")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -Wno-unused-parameter -fPIC")
include (CheckSymbolExists)

set(CMAKE_MACOSX_RPATH 0) # to disable MAC OS warnings

if (NOT PYTHON_DESIRED)
    set (PYTHON_DESIRED "3")
endif()

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
ADD_SUBDIRECTORY ("doc")


# configure tests
ENABLE_TESTING ()
ADD_SUBDIRECTORY ("tests/python")
