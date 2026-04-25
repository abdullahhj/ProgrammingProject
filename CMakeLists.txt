cmake_minimum_required(VERSION 3.31)
project(2026project C)

set(CMAKE_C_STANDARD 99)

add_executable(2026project main.c
        waveform.c
        waveform.h
        io.c
        io.h)
