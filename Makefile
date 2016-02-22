TORM = main.o overlord.o minion.o overl
CC = g++
CCFLAGS =-g -std=c++11 -I /usr/include/boost/ -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

all: main.o overlord.o minion.o
	${CC} ${CCFLAGS} -o overlord main.o overlord.o minion.o 

main.o: main.cpp
	${CC} ${CCFLAGS} -c main.cpp

overlord.o: overlord.cc
	${CC} ${CCFLAGS} -c overlord.cc

minion.o: minion.cc 
	${CC} ${CCFLAGS} -c minion.cc

clean:
	rm -r ${TORM}
