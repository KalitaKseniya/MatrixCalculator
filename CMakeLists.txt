cmake_minimum_required(VERSION 3.14)
project(MatrixCalculator)

set(CMAKE_CXX_STANDARD 17)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})



add_executable(main main.cpp controls_id.h)
target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLFW_LIBRARIES} ${CMAKE_SOURCE_DIR}/libglui_static.a)
