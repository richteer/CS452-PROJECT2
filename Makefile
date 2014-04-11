CPP=g++
CC=gcc

all: main



main: main.o renderobject.o renderer.o init_stuff.o
	${CPP} -o $@ $^ -lGL -lglfw -lGLEW

mainfree: mainfree.o renderobject.o renderer.o init_stuff.o
	${CPP} -o $@ $^ -lGL -lglfw -lGLEW -lglut

main.o: main.cpp
	${CPP} -c -g $^

mainfree.o: mainfree.cpp
	${CPP} -c -g $^

renderobject.o: renderobject.cpp renderobject.h
	${CPP} -c -g $^

renderer.o: renderer.cpp renderer.h renderobject.h
	${CPP} -c -g $<

init_stuff.o: init_stuff.c init_stuff.h
	${CC} -c -g init_stuff.c

clean:
	rm -rf *.o main
