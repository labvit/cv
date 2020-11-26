cmake_minimum_required(VERSION 3.8)

project(demo2d CXX C)
set(OpenGL_GL_PREFERENCE "GLVND")
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
  message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)
set(GL_LIBRARY GL  X11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
if(WIN32)
  set(CMAKE_WIN32_EXECUTABLE ON)
endif()

add_subdirectory(freeglut)
include_directories(freeglut/include)

add_executable(
	demo.exe
	
	spaceball.cpp

	bezier_curve.cpp  
	circle.cpp  
	glcontext.cpp  
	ishape.cpp
	box.cpp	    
	demo.cpp   
	icontext.cpp  
	spaceball.cpp
	vmath.cpp
	vmath.h
	vmath.inl
	${freeglut}
)
target_link_libraries(demo.exe GL freeglut )
