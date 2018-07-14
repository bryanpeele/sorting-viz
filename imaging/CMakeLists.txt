add_library(imaging
        include/image_utils.h
        src/image_utils.cpp
        )

target_include_directories(imaging PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
