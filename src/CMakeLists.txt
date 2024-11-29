add_library(lib lib.cpp lib.hpp)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC lib)