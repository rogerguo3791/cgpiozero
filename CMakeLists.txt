# 指定cmake最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
# 指定工程的名称
PROJECT(CGPIOZERO)


# 查找链接所需的库
find_package(Threads REQUIRED)

# 添加 math 子目录
add_subdirectory(src)

#指定头文件目录位置
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

#添加共享库搜索路径
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量

aux_source_directory(. DIR_SRCS)

#生成可执行文件
ADD_EXECUTABLE(test ${DIR_SRCS})

#为hello添加共享库链接
TARGET_LINK_LIBRARIES(test cgpiozero pigpiod_if2  Threads::Threads)