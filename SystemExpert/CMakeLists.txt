cmake_minimum_required(VERSION 3.26)
project(ProjetLO21 C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetLO21 main.c
        RegleF/RPremisse.h
        RegleF/RPremisse.c
        BaseConnaissanceF/BCF.h
        BaseConnaissanceF/BCF.c
        InferenceF.h
        InferenceF.c
        BaseFaitF/BaseFait.h
        BaseFaitF/BaseFait.c
        BaseFaitF/BaseFait.c
)
