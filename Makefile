default: lbuild

# Linux Build
lbuild: lmain.o lboard.o lgamelogic.o
	g++ -o linuxbuild lmain.o lboard.o lgamelogic.o -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o

lmain.o: src/main.cpp
	g++ -c -o lmain.o src/main.cpp

lboard.o: src/board.cpp
	g++ -c -o lboard.o src/board.cpp 

lgamelogic.o: src/gamelogic.cpp
	g++ -c -o lgamelogic.o src/gamelogic.cpp 