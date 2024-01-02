cmake_minimum_required(VERSION 3.24)
project(Projet_LO21 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_LO21 main.c regle.c inference.c regle.h inference.h baseCo.c baseCo.h InitEssai.c InitEssai.h baseFait.h baseFait.c "template SDL.c" "template SDL.c" interface.c interface.h)

# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/module)
set(SDL2_PATH "SDL2/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})

set(SDL2_IMAGE_PATH "SDL2/SDL2_image/x86_64-w64-mingw32")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})

set(SDL2_TTF_PATH "SDL2/SDL2_ttf/x86_64-w64-mingw32")
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARIES})
