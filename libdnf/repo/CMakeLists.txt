SET (LIBDNF_SOURCES
        ${LIBDNF_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/repo.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/repodict.cpp
        PARENT_SCOPE
        )

SET (LIBDNF_HEADERS
        ${LIBDNF_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/repo.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/repodict.hpp
        PARENT_SCOPE
        )
