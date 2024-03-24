# ./app/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

project(gddr6_app)
set(APP_SOURCES src/app.c)
add_executable(gddr6 ${APP_SOURCES})

target_link_libraries(gddr6 PRIVATE gddr6_lib)
target_link_libraries(gddr6 PRIVATE pci)

set_target_properties(gddr6 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
