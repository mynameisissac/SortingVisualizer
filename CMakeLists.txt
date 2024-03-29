cmake_minimum_required(VERSION 3.20)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(SortingVisualizer 
src/main.cpp 
src/Engine.cpp 
include/Engine.h 
src/handleInput.cpp 
src/Sorting/BogoSort.cpp 
include/Sorting/BogoSort.h 
src/Sorting/SortingAlgorithm.cpp 
include/Sorting/SortingAlgorithm.h 
include/Array.h include/UI_common.h 
src/Sorting/SelectionSort.cpp 
include/Sorting/SelectionSort.h 
src/SideBar.cpp include/SideBar.h
        src/Button/Button.cpp include/Button/Button.h
        src/Button/PauseButton.cpp
        include/Button/PauseButton.h
src/Sorting/BubbleSort.cpp 
include/Sorting/BubbleSort.h 
src/BackGroundUI.cpp 
include/BackGroundUI.h src/Sorting/InsertionSort.cpp include/Sorting/InsertionSort.h src/Sorting/QuickSort.cpp include/Sorting/QuickSort.h src/Menu.cpp include/Menu.h src/Button/SelectionButton.cpp include/Button/SelectionButton.h src/Button/ConfirmButton.cpp include/Button/ConfirmButton.h src/TextBox.cpp include/TextBox.h)

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