# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project(SYNCRequest)

# the version number,like define
set (SYNCRequest_VERSION_MAJOR 1)
set (SYNCRequest_VERSION_MINOR 0)
set (SYNCRequest_VERSION_PATCH 0)

#Debug/Release settings
set (CMAKE_BUILD_TYPE "Debug")
set (CMAKE_CXX_FLAGS "-std=c++11 -O0 -Wall -g -ggdb -lpthread -lACE")
# set (CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -lACE -lpthread")
# set (CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -lACE -lpthread")

# 查找当前目录下的所有源文件
# 并将名称保存到DIR_SRCS变量
aux_source_directory(. DIR_SRCS)
# 指定生成目标
add_executable(SYNCRequest ${DIR_SRCS})
