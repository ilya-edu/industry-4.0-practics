cmake_minimum_required (VERSION 3.8)

project ("DataGetter")

set(CMAKE_CXX_STANDARD 17)

add_executable (DataGetter "src/main.cpp")


if(WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# Humanity curl
include(FetchContent)
FetchContent_Declare(cpr
					 GIT_REPOSITORY https://github.com/libcpr/cpr.git
                     GIT_TAG c4713a704ca12237485ecbfec185f76c2a81bd09 # latest from: https://github.com/libcpr/cpr/releases
)

FetchContent_MakeAvailable(cpr)


target_link_libraries(DataGetter PRIVATE cpr::cpr)
