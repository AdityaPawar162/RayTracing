# CMakeLists.txt

cmake_minimum_required ( VERSION 3.1.0...3.27.0 )

project ( RTWeekend LANGUAGES CXX )

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set ( CMAKE_CXX_EXTENSIONS     ON )


# Add the include directory to the project

# Add the source files to the project
set(SOURCES
# src/main.cpp  # Uncomment this line if main.cpp is your main source file
include/color.hpp
include/ray.hpp
include/sphere.hpp
include/vec3.hpp
include/interval.hpp
include/camera.hpp
include/hittable.hpp
include/hittable_list.hpp
include/utils.hpp
include/material.hpp

src/after_refactoring.cpp

)



include_directories(include)
add_executable(scene ${SOURCES})

# message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPILER_ID})

# target_compile_options(scene PRIVATE
#     # Common optimization flags
#     -O1
# )

# # Compiler-specific optimization flags
# if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#     target_compile_options(scene PRIVATE
#         /Ox  # Full optimization
#     )
# elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     target_compile_options(scene PRIVATE
#         -march=native  # Architecture-specific optimization
#         -funroll-loops  # Loop unrolling
#     )
# elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#     target_compile_options(scene PRIVATE
#         -march=native  # Architecture-specific optimization
#         -funroll-loops  # Loop unrolling
#     )
# endif()


# Create the library
# add_library(scene STATIC src/Scene_rays.cpp)

# Create the executable
# add_executable(main ${SOURCES})



# Set the output directory for the executables
# set_target_properties(main PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
# )

