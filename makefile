CC=g++

.PHONY: all clean

all: ShapeHysteria

ShapeHysteria: Driver.cpp Shapes.o
	$(CC) -o ShapeHysteria Driver.cpp -lm

Shapes.o: Shapes.h
	$(CC) -o Shapes.o Shapes.h

clean:
	$(RM) ShapeHysteria Shapes.o