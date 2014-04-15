CPP=g++
CC=gcc
CPPFLAGS=--std=c++11

all: main

main: main.o renderobject.o renderer.o init_stuff.o bulletmap.o
	${CPP} -o $@ $^ -lGL -lglut

main.o: main.cpp ship.h
	${CPP} -c -g $< ${CPPFLAGS} 

mainfree.o: mainfree.cpp
	${CPP} -c -g $< ${CPPFLAGS} 

renderobject.o: renderobject.cpp renderobject.h
	${CPP} -c -g $< ${CPPFLAGS} 

bulletmap.o: bulletmap.cpp bulletmap.h
	${CPP} -c -g $< ${CPPFLAGS} 

renderer.o: renderer.cpp renderer.h renderobject.h
	${CPP} -c -g $< ${CPPFLAGS} 

init_stuff.o: init_stuff.c init_stuff.h
	${CC} -c -g init_stuff.c

clean:
	rm -rf *.o main
