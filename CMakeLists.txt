# to build:

# mkdir build && cd build

# cmake .. -GNinja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
# -DCMAKE_EXPORT_COMPILE_COMMANDS=true

# ninja

# => executable should be in build file
cmake_minimum_required(VERSION 3.16...3.23)

# standard version cpp
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# project name
project(nanotekspice)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/..)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib/)

include_directories(include/)

# Warning flags
set(GCC_WARNING_FLAGS
    -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches
    -Wlogical-op -Wnull-dereference -Wuseless-cast)

set(CLANG_WARNING_FLAGS
    -Weverything
    -Wno-c++20-compat
    -Wno-c++98-c++11-compat-binary-literal
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-c99-extensions
    -Wno-disabled-macro-expansion
    -Wno-documentation-unknown-command
    -Wno-exit-time-destructors
    -Wno-global-constructors
    -Wno-implicit-int-float-conversion
    -Wno-return-std-move
    -Wno-return-type-c-linkage
    -Wno-signed-enum-bitfield
    -Wno-weak-vtables)

set(WARNING_FLAGS
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -pedantic
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion
    -Wformat=2
    -Weffc++
    -Wno-padded
    -Wno-ctad-maybe-unsupported)

# set different flags
set(CMAKE_BUILD_TYPE
    ${CMAKE_BUILD_TYPE}
    CACHE
      STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel tsan"
      FORCE)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -fdebug-default-version=2")
endif()

# Clang-tidy
if(USE_CLANG_TIDY)
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable")
  if(CLANG_TIDY_EXE)
    if(DEFINED NANOTEKSPICE_CLANG_TIDY_FLAGS)
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}"
                               "${NANOTEKSPICE_CLANG_TIDY_FLAGS}")
    else()
      set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
    message("-- Found clang-tidy: ${CLANG_TIDY_EXE}")
  else()
    message("-- Failed to find clang-tidy")
  endif()
endif()

# set warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(WARNING_FLAGS ${WARNING_FLAGS} ${CLANG_WARNING_FLAGS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(WARNING_FLAGS ${WARNING_FLAGS} ${GCC_WARNING_FLAGS})
else()
  error("${CMAKE_CXX_COMPILER_ID}: Unsupported compiler.")
endif()

# adding executables
add_executable(nanotekspice
    src/main.cpp
    src/Circuit.cpp
    src/components/AComponent.cpp
    src/components/elementary/AndComponent.cpp
    src/components/elementary/OrComponent.cpp
    src/components/elementary/NotComponent.cpp
    src/components/elementary/XorComponent.cpp
    src/components/special/ClockComponent.cpp
    src/components/special/FalseComponent.cpp
    src/components/special/InputComponent.cpp
    src/components/special/OutputComponent.cpp
    src/components/special/TrueComponent.cpp
    src/components/gates/4001Component.cpp
    src/components/gates/4011Component.cpp
    src/components/gates/4030Component.cpp
    src/components/gates/4069Component.cpp
    src/components/gates/4071Component.cpp
    src/components/gates/4081Component.cpp
    src/components/advanced/4008Component.cpp
    src/components/BooleanOperations.cpp
    src/parsing/Parser.cpp
    src/parsing/load_circuit.cpp
    src/parsing/utils_parser.cpp)

# include directories
target_compile_options(nanotekspice PRIVATE ${WARNING_FLAGS})
set_property(TARGET nanotekspice PROPERTY CXX_STANDARD 20)
set_property(TARGET nanotekspice PROPERTY CXX_STANDARD_REQUIRED ON)
