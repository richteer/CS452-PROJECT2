CC=g++

main: main.cpp renderobject.o renderer.o init_stuff.o
	${CC} -o $@ $^ -lGL -lglfw

renderobject.o: renderobject.cpp renderobject.h
	${CC} -c $^

renderer.o: renderer.cpp renderer.h renderobject.h
	${CC} -c $<

init_stuff.o: init_stuff.c init_stuff.h
	gcc -c init_stuff.c

clean:
	rm -rf *.o main
