cmake_minimum_required(VERSION 3.26)
project(ProjetLO21 C)

set(CMAKE_C_STANDARD 99)

add_executable(ProjetLO21
        RegleF/RPremisse.h
        RegleF/RPremisse.c
        BaseConnaissanceF/BCF.h
        BaseConnaissanceF/BCF.c
        Inference/InferenceF.h
        Inference/InferenceF.c
        BaseFaitF/BaseFait.h
        BaseFaitF/BaseFait.c
        BaseFaitF/BaseFait.c
        main.c
        JeuF/JeuFonction.c
        JeuF/JeuFonction.h
)
