cmake_minimum_required(VERSION 4.0)
project(from_lexue)

set(CMAKE_CXX_STANDARD 14)

add_executable(from_lexue
        "数据结构（C)/栈和队列/test.cpp"
        "数据结构（C)/栈和队列/1.cpp"
        "数据结构（C)/线性表/text.cpp"
        "数据结构（C)/线性表/一元多项式相乘.cpp"
        "数据结构（C)/线性表/求循环小数.cpp"
        "数据结构（C)/线性表/求循环节起点.cpp"
        "数据结构（C)/线性表/迷宫.cpp"
        "数据结构（C)/线性表/链表原地逆序.cpp"
        "数据结构（C)/线性表/集合基本操作.cpp"
        离散/求命题公式主范式.cpp
        离散/消解算法.cpp)
