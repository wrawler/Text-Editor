cmake_minimum_required(VERSION 3.6.0)
project(TextEditor2 VERSION 0.1.0)

set(OpenGL_GL_PREFERENCE GLVND)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/imgui)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib/nativefiledialog)

# Add your additional source files
set(ADDITIONAL_SOURCES
    MyApp.hpp 
    lib/nativefiledialog/src/include/nfd.hpp 
    openDialog.cpp 
    FileDialog.hpp
    Menu_bar.hpp
    saveDialog.cpp
)

# Add GLFW include directories
include_directories(${CMAKE_SOURCE_DIR}/lib/imgui)
include_directories(${CMAKE_SOURCE_DIR}/lib/glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/nativefiledialog/src/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/fonts/)

# Add GLFW library
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/glfw/libglfw3.a)

# adding executables
add_executable(TextEditor2 main.cpp ${ADDITIONAL_SOURCES})

# Add ImGui source directory
target_link_libraries(TextEditor2 PUBLIC imgui glfw)

# Add native File dialog source
target_link_libraries(TextEditor2 PUBLIC nfd)

# Link the OpenGL library
find_package(OpenGL REQUIRED)
target_link_libraries(TextEditor2 PRIVATE OpenGL::GL)