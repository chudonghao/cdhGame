
add_library(
    ${PROJECT_NAME}_match
    STATIC
    Match.cpp
    Match.h
)

target_link_libraries(
    ${PROJECT_NAME}_match
    Qt5::Core
)
