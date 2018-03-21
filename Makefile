prog: main.o Minheap.o Maxheap.o
	g++ -g -Wall -std=c++11 main.o Minheap.o Maxheap.o -o prog

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

Minheap.o: Minheap.cpp Minheap.h Heap.h
	g++ -g -Wall -std=c++11 -c Minheap.cpp

Maxheap.o: Maxheap.cpp Maxheap.h Heap.h
	g++ -g -Wall -std=c++11 -c Maxheap.cpp

clean:
	rm *.o prog
