add_executable(sample src/sample.cpp)
target_link_libraries(sample
        imaging
        sorting
        )

add_executable(bubble_sample src/bubble_sample.cpp)
target_link_libraries(bubble_sample
        imaging
        sorting
        )