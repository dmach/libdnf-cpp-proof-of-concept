SET (LIBDNF_SOURCES
        ${LIBDNF_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/bgettext.c
        PARENT_SCOPE
        )

SET (LIBDNF_HEADERS
        ${LIBDNF_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/bgettext-common.h
        ${CMAKE_CURRENT_SOURCE_DIR}/bgettext-lib.h
        ${CMAKE_CURRENT_SOURCE_DIR}/bgettext.h
        PARENT_SCOPE
        )
