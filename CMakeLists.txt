# Min CMake version
cmake_minimum_required(VERSION 3.18)
project(LinuxModulesProject CXX)

# Set directory vars
set(SOURCE_DIR "source")
set(INCLUDE_DIR "include")
set(SOURCE_TESTS_DIR "source_tests")
set(INCLUDE_TESTS_DIR "include_tests")

message(STATUS "Building for Unix")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Main executable
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")
add_library(LinuxModulesLib
	${SOURCES}
)

# Test executable#
add_executable(LinuxModulesTests
	${SOURCE_TESTS_DIR}/LinuxModulesTests.cpp
)

if (NOT TARGET BaseModuleLib)
        add_subdirectory(components/Base_Module)
endif()

find_library(ALSA_LIBRARY asound)     
target_link_libraries(LinuxModulesLib ${ALSA_LIBRARY})

# Include directories for main code and tests
target_include_directories(LinuxModulesLib
	PRIVATE ${INCLUDE_DIR}
	PRIVATE ${INCLUDE_TESTS_DIR}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/components/Nlohmann_JSON/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/components/Nlohmann_JSON/include/nlohmann
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/plog/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/include
)

#target_include_directories(LinuxModulesTests
#	PRIVATE ${INCLUDE_DIR}
#	PRIVATE ${INCLUDE_TESTS_DIR}
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/components/doctest/doctest
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/components/Nlohmann_JSON/include
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/components/Nlohmann_JSON/include/nlohmann
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/Chunk_Types/include
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/components/plog/include
#	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/components/Base_Module/include
#)

# Library A which need B shall be listed before B
target_link_libraries(LinuxModulesTests PRIVATE LinuxModulesLib BaseModuleLib ChunkTypesLib doctest::doctest)

# Enable testing
enable_testing()

# Add tests to CTest
add_test(NAME linuxModulesTests COMMAND LinuxModulesTests)
