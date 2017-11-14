obj = main.o point.o

all: $(obj)
	g++ -o meshSimplification $(obj)
point.o: point.h
main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm meshSimplification *.o *.obj
