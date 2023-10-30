all: task3

task3: main.o print.o
	g++ main.o print.o -o task3

main.o: main.cpp
	g++ -c main.cpp

print.o: print.cpp
	g++ -c print.cpp

clean:
	rm -rf *.o task3
