cmake_minimum_required(VERSION 3.10)
project(advanced VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_DFS "Use custom DFS algorithm" ON)

configure_file(include/advancedConfig.h.in advancedConfig.h)

if(USE_DFS)
    add_subdirectory(CustomDFS)
    list(APPEND EXTRA_LIBS CustomDFS)
endif()

set(SOURCE src/advanced.cpp)
add_executable(advanced ${SOURCE})
target_link_libraries(advanced PUBLIC ${EXTRA_LIBS})
target_include_directories(advanced PUBLIC "${PROJECT_BINARY_DIR}")

set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install")
install(TARGETS advanced DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/advancedConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${advanced_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${advanced_VERSION_MINOR}")
include(CPack)

if(WIN32)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT advanced)
endif()
