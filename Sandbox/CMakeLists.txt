file(GLOB_RECURSE SRC src/*.cpp)

add_executable(Sandbox ${SRC})

target_link_libraries(Sandbox PRIVATE SakuraRenderEngine)

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)