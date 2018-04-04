# Masukkan semua file cpp Anda
OBJS = oop.cpp main.cpp

CC = g++
COMPILER_FLAGS = -IC:\mingw_dev_lib\include\SDL2 -std=c++11 -Wall -O2
LINKER_FLAGS =  -LC:\mingw_dev_lib\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)