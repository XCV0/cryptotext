cmake_minimum_required(VERSION 3.5)

project(CryptoText)

# Find the Qt library
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files
set(SOURCES
    main.cpp
    main.h
    # Add other source files here
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
