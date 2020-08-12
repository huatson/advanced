add_library(Combinatory Combinatory.cpp)

target_include_directories(Combinatory INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

message("Library source dir ${CMAKE_CURRENT_SOURCE_DIR}")
message("Library binary dir ${CMAKE_CURRENT_BINARY_DIR}")

install(TARGETS Combinatory DESTINATION lib)
install(FILES Combinatory.h DESTINATION include)

