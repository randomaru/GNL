cmake_minimum_required(VERSION 3.13)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(get_next_line
        get_next_line.c
        get_next_line.h
        main.c
        file.txt
        cmake-build-debug/libft/ft_strchr.c
        cmake-build-debug/libft/ft_strdel.c
        cmake-build-debug/libft/ft_strdup.c
        cmake-build-debug/libft/ft_strjoin.c
        cmake-build-debug/libft/ft_strlen.c
        cmake-build-debug/libft/ft_strsub.c
        cmake-build-debug/libft/ft_strnew.c)
