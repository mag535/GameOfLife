# Melissa Gray
# 9/16/2022

CC=g++
SRC=src
OBJ=obj
BIN=bin
TESTS=initTests

# all: bin/gameOfLife obj/cell.o obj/table.o

obj/cell.o: src/cell.c src/cell.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/cell.o src/cell.c

obj/table.o: src/table.c src/table.h
	[ -d $(OBJ) ] || mkdir -p $(OBJ)
	${CC} -c -o obj/table.o src/table.c

bin/gameOfLife: obj/cell.o obj/table.o src/gameOfLife.cpp
	[ -d $(BIN) ] || mkdir -p $(BIN)
	${CC} -o bin/gameOfLife obj/cell.o obj/table.o src/gameOfLife.cpp

test01: bin/gameOfLife
	bin/gameOfLife iState01.txt
test02: bin/gameOfLife
	bin/gameOfLife iState02.txt

clean:
	rm -f obj/cell.o
	rm -f obj/table.o
	rm -f bin/gameOfLife
	rm -f -d bin
	rm -f -d obj
