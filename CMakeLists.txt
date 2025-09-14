# ////////////////////////////////////////////////////////////////////////////
# //////////// You Shold Build This CMakeLists For Twice !!!//////////////////
# //// If you cann't build it, try to generate it (Ctrl + S)!!!///////////////
# ////////////////////////////////////////////////////////////////////////////

cmake_minimum_required (VERSION 3.2)

project (Sakura LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)

option(GLFW_BUILD_WIN32 "Build support for Win32" ON)
option(GLFW_BUILD_COCOA "Build support for Cocoa" OFF)
option(GLFW_BUILD_X11 "Build support for X11" OFF)
option(GLFW_BUILD_WAYLAND "Build support for Wayland" OFF)

add_subdirectory (ThirdParty/glfw)
add_subdirectory (SakuraRenderEngine)
add_subdirectory (Sandbox)