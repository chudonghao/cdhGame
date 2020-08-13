
add_subdirectory(3d)
add_subdirectory(ui)
add_subdirectory(match)
add_subdirectory(runtime)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}

    ${PROJECT_NAME}_3d
    ${PROJECT_NAME}_match
    ${PROJECT_NAME}_runtime

    Qt5::Core
    Qt5::Widgets
    ${OPENSCENEGRAPH_LIBRARIES}
)
