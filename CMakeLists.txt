cmake_minimum_required(VERSION 3.27)
project(05_HikeTracker)

set(CMAKE_CXX_STANDARD 17)

# IMPORTANT: Enable CTest support
enable_testing()

# -----------------------------
# Header-only "library"
# -----------------------------
add_library(mylib INTERFACE)


target_include_directories(mylib INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Main program
add_executable(05_HikeTracker
        main.cpp
)

target_link_libraries(05_HikeTracker
        PUBLIC ${LIB_NAME}
)
add_subdirectory(tests)
