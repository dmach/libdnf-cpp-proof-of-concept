CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/conf.py.in ${CMAKE_CURRENT_BINARY_DIR}/conf.py)

ADD_CUSTOM_TARGET (doxygen
    doxygen ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    COMMENT "Building doxygen xml files")
ADD_CUSTOM_TARGET (doc-html
    sphinx-build -c ${CMAKE_CURRENT_BINARY_DIR} -b html
                 ${CMAKE_CURRENT_SOURCE_DIR}
                 ${CMAKE_CURRENT_BINARY_DIR}/_build
    COMMENT "Building html documentation")
ADD_CUSTOM_TARGET (doc)
ADD_DEPENDENCIES (doc-html doxygen)
ADD_DEPENDENCIES (doc doc-html)
