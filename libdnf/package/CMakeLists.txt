SET (LIBDNF_HEADERS
        ${LIBDNF_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/modulepackage.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/package.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/rpmpackage.hpp
        PARENT_SCOPE
        )

SET (LIBDNF_SOURCES
        ${LIBDNF_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/modulepackage.cpp
        PARENT_SCOPE
        )