cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

# Recommended for cygwin on windows.
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project (linear_algebra C CXX)

set (linear_algebra_VERSION_MAJOR 0)
set (linear_algebra_VERSION_MINOR 2)

# All binaries will go in /bin and all libaraies in /lib
# Found at http://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# The following was set up using the tutorial found at
# https://www.johnlamp.net/cmake-tutorial-1-getting-started.html

#Set compile flags for common compilers
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "--std=c++11 -Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(warnings "/W4 /WX /EHsc")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}"
      CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

# Provide information to the library, such as version numbers"
configure_file(
    "${PROJECT_SOURCE_DIR}/include/LinearAlgebraConfig.h.in"
    "${PROJECT_BINARY_DIR}/LinearAlgebraConfig.h"
    )

# Include files 
set(Project_Include_dir ${CMAKE_SOURCE_DIR}/include)
set(Project_Source_dir ${CMAKE_SOURCE_DIR}/src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR})

# The following is taken with only minor edits from
# www.kaizou.org/2014/11/gtest-cmake
# Very helpful
option(BUILD_TESTS " download and build all tests" FALSE)
if (BUILD_TESTS)
  # We need thread support
  find_package(Threads REQUIRED)

  # Enable ExternalProject CMake module
  include(ExternalProject)

  # Download and install GoogleTest
  ExternalProject_Add(
    gtest
    URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
  )
#set_target_properties(gtest PROPERTIES EXCLUDE_FROM_ALL TRUE)
  # Create a libgtest target to be used as a dependency by test programs
  add_library(libgtest STATIC IMPORTED GLOBAL)
  add_dependencies(libgtest gtest)

  # Set gtest properties
  ExternalProject_Get_Property(gtest source_dir binary_dir)
  set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  )
  include_directories(${source_dir}/include)

  # Download and install GoogleMock
  ExternalProject_Add(
    gmock
    URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
    # Disable install step
    INSTALL_COMMAND ""
  )
  # Create a libgmock target to be used as a dependency by test programs
  add_library(libgmock STATIC IMPORTED GLOBAL)
  add_dependencies(libgmock gmock)

  # Set gmock properties
  ExternalProject_Get_Property(gmock source_dir binary_dir)
  set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
  )
  include_directories(${source_dir}/include)

  # Allow testing
  enable_testing()

endif(BUILD_TESTS)

# Add my project files
add_subdirectory(src)

# Sets flag to tell if cmake has already been ran.
set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")
