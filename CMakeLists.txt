cmake_minimum_required (VERSION 3.9)
project (algorithm)
set (algorithm_VERSION_MAJOR 0)
set (algorithm_VERSION_MINOR 1)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (CXX_COMPILER_WARNING_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wold-style-cast -Wcast-align")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wunused -Woverloaded-virtual")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wpedantic -Wconversion")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wsign-conversion")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wmisleading-indentation")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wduplicated-cond")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wduplicated-bracnhes -Wlogical-op")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wnull-dereference -Wuseless-cast")
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wdouble-promotion -Wformat=2")
set (CXX_COMPILER_DEBUG_FLAGS "-g -O0")
set (CXX_COMPILER_RELEASE_FLAGS "-O2")
set (CXX_COMPILER_ASAN_FLAGS "${CXX_COMPILER_RELEASE_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
set (CXX_COMPILER_MSAN_FLAGS "${CXX_COMPILER_RELEASE_FLAGS} -fsanitize=memory -fno-omit-frame-pointer")
set (COVERAGE_FLAGS "${CXX_COMPILER_DEBUG_FLAGS} -ftest-coverage --coverage")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_WARNING_FLAGS}")
set (CMAKE_CC_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_WARNING_FLAGS}")
set (CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS}")

#---------------------------------------------------------------------------------------------------
# Clang Tidy
#---------------------------------------------------------------------------------------------------
if (ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_BIN clang-tidy)

  if (CLANG_TIDY_BIN STREQUAL "CLANG_TIDY_BIN-NOTFOUND")
    message(FATAL_ERROR "unable to locate clang-tidy")
  endif()

  list(APPEND CLANG_TIDY_BIN_ARGS
    -header-filter=${PROJECT_SOURCE_DIR}/include/*.hpp
    -checks=performance-*,clang-analyzer-*,cppcoreguidelines-*,modernize-*,readability-*
  )

  add_custom_target(
    tidy
    COMMAND ${CLANG_TIDY_BIN} ${CLANG_TIDY_BIN_ARGS} ${PROJECT_SOURCE_DIR}/include/*.hpp -- ${CMAKE_CXX_FLAGS}
    COMMENT "running clang tidy"
  )
endif()

#---------------------------------------------------------------------------------------------------
# Clang Format
#---------------------------------------------------------------------------------------------------
if (ENABLE_CLANG_FORMAT)
  find_program(CLANG_FORMAT_BIN clang-format)

  if (CLANG_FORMAT_BIN STREQUAL "CLANG_FORMAT_BIN-NOTFOUND")
    message(FATAL_ERROR "unable to locate clang-format")
  endif()

  list(APPEND CLANG_FORMAT_BIN_ARGS
    -style=file
    -i
  )

  add_custom_target(
    format
    COMMAND ${CLANG_FORMAT_BIN} ${CLANG_FORMAT_BIN_ARGS} ${PROJECT_SOURCE_DIR}/include/*.hpp --
    COMMENT "running clang tidy"
  )
endif()


#---------------------------------------------------------------------------------------------------
# Coverage
#---------------------------------------------------------------------------------------------------
if (ENABLE_COVERAGE)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_FLAGS}")
  set (CMAKE_CC_FLAGS "${CMAKE_CC_FLAGS} ${COVERAGE_FLAGS}")
  set (CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} ${COVERAGE_FLAGS}")
  include(CodeCoverage)
  setup_target_for_coverage(${PROJECT_NAME}_coverage test-algorithm lcov)
endif()

#---------------------------------------------------------------------------------------------------
# Address Sanitizer
#---------------------------------------------------------------------------------------------------
if (ENABLE_ASAN)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_ASAN_FLAGS}")
  set (CMAKE_CC_FLAGS "${CMAKE_CC_FLAGS} ${CXX_COMPILER_ASAN_FLAGS}")
  set (CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} ${CXX_COMPILER_ASAN_FLAGS}")
  set (CMAKE_LINKER "clang++")
endif()

#---------------------------------------------------------------------------------------------------
# Memory Sanitizer
#---------------------------------------------------------------------------------------------------
if (ENABLE_MSAN)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_MSAN_FLAGS}")
  set (CMAKE_CC_FLAGS "${CMAKE_CC_FLAGS} ${CXX_COMPILER_MSAN_FLAGS}")
  set (CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} ${CXX_COMPILER_MSAN_FLAGS}")
  set (CMAKE_LINKER "clang++")
endif()

#---------------------------------------------------------------------------------------------------
# Debug Build
#---------------------------------------------------------------------------------------------------
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_DEBUG_FLAGS}")
  set (CMAKE_CC_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_DEBUG_FLAGS}")
endif()

#---------------------------------------------------------------------------------------------------
# Release Build
#---------------------------------------------------------------------------------------------------
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_RELEASE_FLAGS}")
  set (CMAKE_CC_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_COMPILER_RELEASE_FLAGS}")
endif()


find_package (Threads REQUIRED)
include (ExternalProject)

ExternalProject_Add(
  gtest
  URL https://github.com/google/googletest/archive/master.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
set_target_properties (libgtest PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgtest_main IMPORTED STATIC GLOBAL)
add_dependencies(libgtest_main gtest)
set_target_properties (libgtest_main PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest_main.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)
set_target_properties (libgmock PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")


add_library (algorithm INTERFACE)
target_include_directories (algorithm INTERFACE include/)

file (GLOB SRCS test/*.cpp)
add_executable(test-algorithm ${SRCS})

target_link_libraries(test-algorithm
  algorithm
  libgtest
  libgtest_main
)

install (TARGETS test-algorithm DESTINATION bin)
