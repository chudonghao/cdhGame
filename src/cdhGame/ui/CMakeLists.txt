
add_library(
    ${PROJECT_NAME}_ui
    STATIC
    MainWindow.cpp
    MainWindow.h
)

target_link_libraries(
    ${PROJECT_NAME}_ui
    Qt5::Core
)
