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

add_executable(cocktail_sample src/cocktail_sample.cpp)
target_link_libraries(cocktail_sample
        imaging
        sorting
        )

add_executable(insertion_sample src/insertion_sample.cpp)
target_link_libraries(insertion_sample
        imaging
        sorting
        )