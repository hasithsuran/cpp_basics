cmake_minimum_required(VERSION 3.5)

set(LIBRARY_NAME "core_lib")
set(SOURCE_DIR "src")
set(INCLUDE_DIR "include")

project(${LIBRARY_NAME}
        VERSION 0.0.1
        DESCRIPTION "C++ core demonstration library"
        LANGUAGES CXX)
set(CMAKE_CXX_FLAGS "-Wall")

set(SOURCES ${SOURCES} 
        ${SOURCE_DIR}/TC_BitwiseOp.cpp
        ${SOURCE_DIR}/TC_Lambda.cpp
        ${SOURCE_DIR}/TC_Memory.cpp
        ${SOURCE_DIR}/TC_Optional.cpp
        ${SOURCE_DIR}/TC_Varient.cpp
)

ADD_LIBRARY(${LIBRARY_NAME} STATIC ${SOURCES})
target_include_directories(${LIBRARY_NAME} PRIVATE ${INCLUDE_DIR})
target_compile_features(${LIBRARY_NAME} PRIVATE cxx_std_20)