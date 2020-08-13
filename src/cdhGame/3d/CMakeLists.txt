
add_library(
    ${PROJECT_NAME}_3d
    STATIC
    Viewer.cpp
    Viewer.h
)

target_link_libraries(
    ${PROJECT_NAME}_3d
    Qt5::Core
    ${OSGEARTH_LIBRARIES}
)
