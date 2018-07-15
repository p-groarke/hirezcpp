cmake_minimum_required (VERSION 3.10)
project(hirezcpp CXX)

include (ExternalProject)
include(GoogleTest)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)

# Require up-to-date compiler.
set(CMAKE_CXX_STANDARD 17)

# Organize unrelated targets to clean IDE hierarchy.
set(DEPENDENCY_FOLDER "Dependencies")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER ${DEPENDENCY_FOLDER})

# Output binary to predictable location (fixes cyclic dependency issues).
set(BINARY_OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_OUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_OUT_DIR})

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
	string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BINARY_OUT_DIR})
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BINARY_OUT_DIR})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BINARY_OUT_DIR})
endforeach(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

# Conan things.
include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)

# Tree Lib
file(GLOB_RECURSE LIB_HEADERS "include/*.hpp" "include/*.h" "include/*.tpp")
file(GLOB_RECURSE LIB_SOURCES "src/*.cpp" "src/*.c" "src/*.hpp" "src/*.h" "src/*.tpp")
add_library(${PROJECT_NAME} ${LIB_HEADERS} ${LIB_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME} PUBLIC include) # Interface.
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(${PROJECT_NAME} PUBLIC CONAN_PKG::cpprestsdk CONAN_PKG::date CONAN_PKG::jsonformoderncpp)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.clang-format ${CMAKE_CURRENT_BINARY_DIR}/.clang-format COPYONLY)

##
# Tests
##
option(BUILD_TESTING "Build and run tests." On)

if (${BUILD_TESTING})
	enable_testing()

	set(TEST_NAME ${PROJECT_NAME}_tests)
	file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp" "tests/*.c" "tests/*.hpp" "tests/*.h" "tests/*.tpp")
	add_executable(${TEST_NAME} ${TEST_SOURCES})
	target_link_libraries(${TEST_NAME} ${PROJECT_NAME} CONAN_PKG::gtest)

	gtest_discover_tests(${TEST_NAME})

	if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
		target_compile_options(${TEST_NAME} PRIVATE -Wall -Wextra)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		target_compile_options(${TEST_NAME} PRIVATE -Wall -Wextra)
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
		# using Intel C++
	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${TEST_NAME})
		target_compile_options(${TEST_NAME} PRIVATE /W4 /Zc:__cplusplus /permissive-)#/EHsc 
		add_definitions(-DNOMINMAX -D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
	endif()
endif()

##
# Benchmarks
##
# option(BUILD_BENCHMARKS "Build benchmarks." On)

# if (${BUILD_BENCHMARKS})
# 	set(BENCHMARKS_NAME ${PROJECT_NAME}_benchmarks)
# 	file(GLOB_RECURSE BENCHMARKS_SOURCES "benchmarks/*.cpp" "benchmarks/*.c" "benchmarks/*.hpp" "benchmarks/*.h" "benchmarks/*.tpp")
# 	add_executable(${BENCHMARKS_NAME} ${BENCHMARKS_SOURCES})
# 	target_include_directories(${BENCHMARKS_NAME} PRIVATE  ${CMAKE_CURRENT_BINARY_DIR}/include)
# 	target_link_libraries(${BENCHMARKS_NAME} ${PROJECT_NAME} CONAN_PKG::glm)

# 	ExternalProject_Add(bench_util_ext
# 		GIT_REPOSITORY https://github.com/p-groarke/bench_util.git
# 		CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release #${CMAKE_ARGS}
# 			-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}
# 			-DCMAKE_PREFIX_PATH=${CMAKE_CURRENT_BINARY_DIR}
# 			-DBUILD_EXAMPLES=Off
# 		UPDATE_COMMAND ""
# 	)

# 	set_target_properties(bench_util_ext PROPERTIES FOLDER ${DEPENDENCY_FOLDER})
# 	add_dependencies(${BENCHMARKS_NAME} bench_util_ext)

# 	if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
# 		target_compile_options(${BENCHMARKS_NAME} PRIVATE -Wall -Wextra)
# 	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
# 		target_compile_options(${BENCHMARKS_NAME} PRIVATE -Wall -Wextra)
# 	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
# 		# using Intel C++
# 	elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
# 		target_compile_options(${BENCHMARKS_NAME} PRIVATE /W4 /EHsc /Zc:__cplusplus /permissive-)
# 		add_definitions(-DNOMINMAX)
# 	endif()

# endif()
