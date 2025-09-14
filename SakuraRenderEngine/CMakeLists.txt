file(GLOB_RECURSE SRC src/*.cpp)

add_library(SakuraRenderEngine SHARED ${SRC})

target_include_directories(SakuraRenderEngine 
		PUBLIC 
		include)

# ---------------------- Library Config -----------------------
# Define the DLL list if need to be copied to bin dirctories
set(DLL_FILES
    "${GLFW_BINARY_DIR}/src/glfw3.dll"
)

# Output directories
set(DLL_DEST_DIR ${CMAKE_BINARY_DIR}/bin)
set(LIB_DEST_DIR ${CMAKE_BINARY_DIR}/lib)
    
# -------------------------- Windows --------------------------
if(WIN32)
    # 动态库符号导出
    target_compile_definitions(SakuraRenderEngine PRIVATE MYMATHLIB_EXPORTS)
    set_target_properties(SakuraRenderEngine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${DLL_DEST_DIR}  # .dll 
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_DEST_DIR}  # .lib 
    )

    # 为每个DLL文件创建拷贝命令
    foreach(DLL_FILE ${DLL_FILES})
        if(EXISTS ${DLL_FILE}) 
            get_filename_component(DLL_FILENAME ${DLL_FILE} NAME)
            message(STATUS "Looking for ${DLL_FILENAME} at: ${DLL_FILE}")
            file(MAKE_DIRECTORY ${DLL_DEST_DIR})
    
            add_custom_command(TARGET SakuraRenderEngine POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${DLL_FILE}"
                "${DLL_DEST_DIR}"
                COMMENT "Coping ${DLL_FILENAME} to output directory: ${DLL_DEST_DIR}")  
    
                if(NOT EXISTS ${DLL_DEST_DIR}/${DLL_FILENAME})
                    message(WARNING "Fail to copy ${DLL_FILE} to output directory: ${DLL_DEST_DIR}")
                endif()
        else() 
            message(WARNING "Not find ${DLL_FILENAME}（path：${DLL_FILE}")  
        endif()  
    endforeach()

endif()

# -------------------------- Other OS --------------------------




# -------------------------- Link Libraries --------------------------
target_link_libraries(SakuraRenderEngine PUBLIC glfw)
target_include_directories(SakuraRenderEngine PUBLIC "${GLFW_SOURCE_DIR}/deps")

find_package(Vulkan REQUIRED) # Window 系统需要配置环境变量
target_link_libraries(SakuraRenderEngine PUBLIC Vulkan::Vulkan)

# Show Vulkan Info
message(STATUS "Vulkan_DIR: ${Vulkan_DIR}")
message(STATUS "Vulkan_INCLUDE_DIR: ${Vulkan_INCLUDE_DIR}")
message(STATUS "Vulkan_LIBRARY: ${Vulkan_LIBRARY}")