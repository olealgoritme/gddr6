# ./lib/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(gddr6_lib)
set(LIB_SOURCES src/gddr6.c)

# Static library (libgddr6)
add_library(gddr6_lib STATIC ${LIB_SOURCES})
target_include_directories(gddr6_lib PUBLIC include)

set_target_properties(gddr6_lib PROPERTIES
    OUTPUT_NAME "gddr6" # rename libgddr6_lib.a to libgddr6.a
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
