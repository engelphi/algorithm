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
set (CXX_COMPILER_WARNING_FLAGS "${CXX_COMPILER_WARNING_FLAGS} -Wnull-dereference")
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
    -header-filter=${PROJECT_SOURCE_DIR}/*.hpp
    -checks=performance-*,clang-analyzer-*,cppcoreguidelines-*,modernize-*,readability-*
  )

  add_custom_target(
    tidy
    COMMAND ${CLANG_TIDY_BIN} ${CLANG_TIDY_BIN_ARGS} ${PROJECT_SOURCE_DIR}/algorithms/*.hpp ${PROJECT_SOURCE_DIR}/algorithms/internal/*.hpp -- -std=c++17 ...
    COMMENT "running clang-tidy"
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
    COMMAND ${CLANG_FORMAT_BIN} ${CLANG_FORMAT_BIN_ARGS} ${PROJECT_SOURCE_DIR}/algorithms/*.hpp ${PROJECT_SOURCE_DIR}/algorithms/internal/*.hpp --
    COMMENT "running clang-format"
  )
endif()

#---------------------------------------------------------------------------------------------------
# CppCheck
#---------------------------------------------------------------------------------------------------
if (ENABLE_CPP_CHECK)
  find_program(CPP_CHECK_BIN cppcheck)
  if (CPP_CHECK_BIN STREQUAL "CPP_CHECK_BIN-NOTFOUND")
    message(FATAL_ERROR "unable to locate cppcheck")
  endif()

  list(APPEND CPP_CHECK_BIN_ARGS
    --error-exitcode=1
    --enable=all
    --report-progress
    --platform=unix64
    --std=c++11 
    -I ${PROJECT_SOURCE_DIR}/include/
    -q
  )

  add_custom_target(
    cppcheck
    COMMAND ${CPP_CHECK_BIN} ${CPP_CHECK_BIN_ARGS} ${PROJECT_SOURCE_DIR}/algorithms/*.hpp ${PROJECT_SOURCE_DIR}/algorithms/internal/*.hpp
    COMMENT "running cppcheck"
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

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
set(ALGORITHMS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/algorithms)
add_library (algorithm INTERFACE)
add_library(Catch INTERFACE)
target_include_directories (algorithm INTERFACE ${ALGORITHMS_INCLUDE_DIR})
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

file (GLOB SRCS test/*.cpp)
add_executable(test-algorithm ${SRCS})

target_link_libraries(test-algorithm
  algorithm
  Catch
)

install (TARGETS test-algorithm DESTINATION bin)
