cmake_minimum_required(VERSION 3.17...4.0)
project(imageRGB C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror=vla")

add_executable(main main.c imageRGB.c test.c BMPFile_teacher.o BMPFile.c)