add_library( sorting
        include/bubble.h
        src/bubble.cpp
        include/sort_utils.h
        src/sort_utils.cpp
        )

target_link_libraries(sorting
        imaging
        )

target_include_directories(sorting PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
