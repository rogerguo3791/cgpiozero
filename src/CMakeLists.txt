# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT (LIB)

#指定头文件目录位置
INCLUDE_DIRECTORIES(../include)
# 指定输出 .so 动态库的目录位置
SET(LIBRARY_OUTPUT_PATH ../lib)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library (cgpiozero STATIC ${DIR_LIB_SRCS})
