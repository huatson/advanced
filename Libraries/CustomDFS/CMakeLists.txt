# anadir dfs para usar en 
# <https://leetcode.com/problems/binary-tree-level-order-traversal/>
add_library(CustomDFS CustomDFS.cpp)

target_include_directories(CustomDFS INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

message("Library source dir ${CMAKE_CURRENT_SOURCE_DIR}")
message("Library binary dir ${CMAKE_CURRENT_BINARY_DIR}")

configure_file(input.txt input.txt COPYONLY)

install(TARGETS CustomDFS DESTINATION lib)
install(FILES CustomDFS.h DESTINATION include)
install(FILES input.txt DESTINATION data)
