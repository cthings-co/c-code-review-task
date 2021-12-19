cmake_minimum_required(VERSION 3.10)

project(median_filter)

set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(inc_dir ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(median_filter ${src_dir}/main.c ${src_dir}/median_filter.c)

include_directories(
	${inc_dir})
