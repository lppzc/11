cmake_minimum_required(VERSION 3.16)
project(TodoListGUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt6_standard_project_setup()

# 在qt6_add_executable行添加WIN32
qt6_add_executable(TodoListGUI WIN32
    main.cpp
    todolist.h
    todolist.cpp
)

target_link_libraries(TodoListGUI PUBLIC Qt6::Core Qt6::Widgets)
