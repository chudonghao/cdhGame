
add_library(
    ${PROJECT_NAME}_runtime
    STATIC
    App.cpp
    App.h
    Log.cpp
    Log.h
)

target_link_libraries(
    ${PROJECT_NAME}_runtime
    ${PROJECT_NAME}_ui
    ${PROJECT_NAME}_3d
    ${PROJECT_NAME}_match
    Qt5::Core
)
