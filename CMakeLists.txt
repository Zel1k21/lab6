cmake_minimum_required(VERSION 3.23)

set(project "lab6")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST} "term/term.h" "term/term.cpp"   "polynomial/polynomial.h" "polynomial/polynomial.cpp")


target_sources (${project} PRIVATE
)