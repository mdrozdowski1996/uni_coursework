all: clear strdeque strdequeconst main
	g++ -Wall -O2 main.o strdeque.o strdequeconst.o -o main

call: clear strdeque strdequeconst cmain 
	cc -Wall -O2 cmain.o strdeque.o strdequeconst.o -lstdc++ -o cmain

cmain: cmain.c
	gcc -Wall -O2 -c cmain.c

strdeque: strdeque.cc strdeque.h
	g++ -Wall -DNDEBUG -O2 -std=c++14  -c strdeque.cc

strdequeconst: strdequeconst.cc strdequeconst.h
	g++ -Wall -DNDEBUG -O2 -std=c++14  -c strdequeconst.cc


main: main.cc
	g++ -Wall -O2 -std=c++14  -c main.cc

clear:
	rm main.o strdeque.o strdequeconst.o main | true 
