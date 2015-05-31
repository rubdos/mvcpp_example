add_executable(app main.cpp)


target_link_libraries(app mvcpp ${CMAKE_THREAD_LIBS_INIT} sqlite3)
