project(RemoteShell)
cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(syracuse)

set(SRC ./src)
set(INCLUDE ./include)

target_sources(syracuse PUBLIC
    ${SRC}/main.cpp
)

target_include_directories(syracuse PUBLIC
    ${INCLUDE}/include
)

target_compile_options(syracuse PUBLIC
    $<$<CXX_COMPILER_ID:MSVC>:/W3 /MD -D_WIN32_WINNT=0x0A00 /D_ITERATOR_DEBUG_LEVEL=0 /permissive- /TP /std:c++17>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>: -Wall -Werror -fPIC -ldl -pthread -O3 -g>
)