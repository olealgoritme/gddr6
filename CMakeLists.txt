# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(gddr6_project)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall")

add_subdirectory(lib)
add_subdirectory(app)

install(TARGETS gddr6
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)

install(TARGETS gddr6_lib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)
