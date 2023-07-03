CC = g++
CFLAGS = -c -Wall
LFLAGS =

# Lista de archivos .cpp y sus respectivos archivos .o
CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(CPP_FILES:.cpp=.o)

# Nombre del archivo ejecutable final
TARGET = Lab

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(LFLAGS) $(OBJ_FILES) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)
