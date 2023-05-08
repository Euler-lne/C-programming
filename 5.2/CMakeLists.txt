cmake_minimum_required(VERSION 3.10.2)

project(5_2)
aux_source_directory(./src SRC_SUB)
aux_source_directory(./ SRC_CUR)
add_executable(${PROJECT_NAME} ${SRC_SUB} ${SRC_CUR})
include_directories(include)
