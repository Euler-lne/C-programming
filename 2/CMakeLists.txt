cmake_minimum_required(VERSION 3.0)

project(Experiment)

aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)

add_executable(${PROJECT_NAME} ${SRC_SUB} ${SRC_CUR})
include_directories(include)