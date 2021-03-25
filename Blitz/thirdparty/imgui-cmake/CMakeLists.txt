cmake_minimum_required(VERSION 3.9)

project("imgui" LANGUAGES CXX C)

set(IMGUI_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui.h
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_glfw.h
        ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_opengl3.h
        ${CMAKE_CURRENT_SOURCE_DIR}/imgui_internal.h
        ${CMAKE_CURRENT_SOURCE_DIR}/imstb_rectpack.h
        ${CMAKE_CURRENT_SOURCE_DIR}/imstb_textedit.h
        ${CMAKE_CURRENT_SOURCE_DIR}/imstb_truetype.h
)

set(IMGUI_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_tables.cpp
)

add_library( imgui ${IMGUI_HEADERS} ${IMGUI_SRC} )

target_include_directories(
        imgui PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/backends/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS imgui EXPORT imgui
        ARCHIVE DESTINATION lib/ COMPONENT libraries
        LIBRARY DESTINATION lib/ COMPONENT libraries
        RUNTIME DESTINATION bin/ COMPONENT libraries
)
