horserace: Horse.o Race.o Main.o
	g++ Horse.o Race.o Main.o -o horserace

Horse.o: Horse.cpp Horse.h
	g++ -c Horse.cpp

Race.o: Race.cpp Race.h
	g++ -c Race.cpp

Main.o: Main.cpp Horse.h Race.h
	g++ -c Main.cpp

build:
	make Horse.o
	make Race.o
	make Main.o
	make horserace

run: horserace
	./horserace

br:
	make build
	make run

clean:
	rm horserace
	rm *.o
