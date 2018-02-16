cmake_minimum_required(VERSION 3.0)
PROJECT(app)

set( CMAKE_CXX_COMPILER "/usr/bin/clang++")
set( CMAKE_CXX_FLAGS "-w -std=c++14")
set( INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set( SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

INCLUDE_DIRECTORIES( ${INCLUDE_DIR} )

ADD_EXECUTABLE(app main.cpp
    "${INCLUDE_DIR}/shader/shaderProgram.h"
    "${SOURCE_DIR}/shader/shaderProgram.cpp"
)

# ------------------------------------------------------
# FIND SFML
# ------------------------------------------------------
find_package (SFML 2 COMPONENTS system window graphics audio REQUIRED)
if (SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries (app ${SFML_LIBRARIES})
endif (SFML_FOUND)

# ------------------------------------------------------
# FIND OPENGL
# ------------------------------------------------------
find_package (OPENGL)
if (OPENGL_FOUND)
  include_directories(${OPENGL_INCLUDE_DIR})
  target_link_libraries (app ${OPENGL_LIBRARIES})
endif (OPENGL_FOUND)

# ------------------------------------------------------
# FIND BOOST
# ------------------------------------------------------
# find_package (BOOST COMPONENTS filesystem)
# if (BOOST_FOUND)
#   include_directories(${BOOST_INCLUDE_DIR})
#   target_link_libraries (app ${BOOST_LIBRARIES})
# endif (BOOST_FOUND)


