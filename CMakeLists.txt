cmake_minimum_required(VERSION 3.20)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortingVisualizer src/main.cpp src/Engine.cpp include/Engine.h src/handleInput.cpp src/BogoSort.cpp include/BogoSort.h src/SortingAlgorithm.cpp include/SortingAlgorithm.h include/Array.h include/UI_common.h src/SelectionSort.cpp include/SelectionSort.h)

include_directories(include "C:/Program Files/SFML-2.5.1/include")

# connect the SFML thing
set(SFML_DIR "C:/Program Files/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS window graphics REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
endif()

# assets files
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build for windows
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/Program Files/mingw-w64/x86_64-7.3.0-posix-seh-rt_v5-rev0/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()