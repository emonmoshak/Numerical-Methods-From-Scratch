cmake_minimum_required(VERSION 3.20)
project(NumericalMethodsFromScratch VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fno-char8_t)
endif()

# Include directories
include_directories(include)

# --- Dependencies ---

include(FetchContent)

# fmt
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        10.1.1 # Adjust version as needed
)
FetchContent_MakeAvailable(fmt)

# Eigen
FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG        3.4.0
)
FetchContent_MakeAvailable(eigen)

# matplotplusplus
FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG        v1.2.0
)
FetchContent_MakeAvailable(matplotplusplus)

# GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Main Library (will contain the implementations)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_link_libraries(${PROJECT_NAME} INTERFACE fmt::fmt Eigen3::Eigen matplot)

# --- Subdirectories ---

# add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(examples)

enable_testing()
