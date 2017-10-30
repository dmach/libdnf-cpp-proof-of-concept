SET (DNF_GI_VERSION 42.0)

# source files used for gir generation
SET (DNF_SWDB_SOURCES
    dnf-swdb-pkg.c
)

SET (DNF_SWDB_HEADERS
    dnf-swdb-pkg.h
)

# gir generation - GObject introspection
# taken from https://github.com/ufo-kit/libuca/blob/master/src/CMakeLists.txt
find_program(INTROSPECTION_SCANNER "g-ir-scanner")
find_program(INTROSPECTION_COMPILER "g-ir-compiler")
pkg_check_modules(GOBJECT_INTROSPECTION gobject-introspection-1.0)

find_package(PkgConfig REQUIRED)
function(pkg_check_variable _pkg _name)
    string(TOUPPER ${_pkg} _pkg_upper)
    string(TOUPPER ${_name} _name_upper)
    string(REPLACE "-" "_" _pkg_upper ${_pkg_upper})
    string(REPLACE "-" "_" _name_upper ${_name_upper})
    set(_output_name "${_pkg_upper}_${_name_upper}")

    execute_process(COMMAND ${PKG_CONFIG_EXECUTABLE} --variable=${_name} ${_pkg}
                    OUTPUT_VARIABLE _pkg_result
                    OUTPUT_STRIP_TRAILING_WHITESPACE)

    set("${_output_name}" "${_pkg_result}" CACHE STRING "pkg-config variable
    ${_name} of ${_pkg}")
endfunction()

if (GOBJECT_INTROSPECTION_FOUND)
    option(WITH_GIR "Build introspection files" ON)

    if (WITH_GIR)
        pkg_check_variable(gobject-introspection-1.0 g_ir_scanner)
        pkg_check_variable(gobject-introspection-1.0 g_ir_compiler)

        set(GIR_PREFIX "Dnf-${DNF_GI_VERSION}")
        set(GIR_XML "${GIR_PREFIX}.gir")
        set(GIR_TYPELIB "${GIR_PREFIX}.typelib")

        add_custom_command(OUTPUT ${GIR_XML}
            COMMAND env CFLAGS=${CMAKE_C_FLAGS} ${GOBJECT_INTROSPECTION_1.0_G_IR_SCANNER}
                    --namespace=Dnf
                    --nsversion=${DNF_GI_VERSION}
                    --library-path=${CMAKE_CURRENT_BINARY_DIR}
                    --library=dnf
                    --no-libtool
                    --include=GObject-2.0
                    --include=Gio-2.0
                    -Idirectory ${CMAKE_CURRENT_SOURCE_DIR}
                    --output ${CMAKE_CURRENT_BINARY_DIR}/${GIR_XML}
                    --pkg=librepo
                    --warn-all
                    --quiet
                    ${DNF_SWDB_SOURCES}
                    ${DNF_SWDB_HEADERS}
            DEPENDS libdnf
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

        add_custom_command(OUTPUT ${GIR_TYPELIB}
            COMMAND ${GOBJECT_INTROSPECTION_1.0_G_IR_COMPILER}
                    -o ${GIR_TYPELIB}
                    ${GIR_XML}
            DEPENDS ${GIR_XML}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
        add_custom_target(gir ALL
                          DEPENDS ${GIR_XML} ${GIR_TYPELIB})

        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${GIR_XML}
                DESTINATION share/gir-1.0
                COMPONENT libraries)
        install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${GIR_TYPELIB}
                DESTINATION ${LIB_INSTALL_DIR}/girepository-1.0
                COMPONENT libraries)
    endif()
endif()
