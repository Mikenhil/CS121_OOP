#Compiles All .o files into an executable
horserace: Horse.o Race.o Main.o
	g++ Horse.o Race.o Main.o -o horserace

# Compiles cpp and header files into .o files
Horse.o: Horse.cpp Horse.h
	g++ -c Horse.cpp

Race.o: Race.cpp Race.h
	g++ -c Race.cpp

Main.o: Main.cpp Horse.h Race.h
	g++ -c Main.cpp

# Builds the entire project
build:
	make Horse.o
	make Race.o
	make Main.o
	make horserace

# Simple run command for already built executable
run: horserace
	./horserace

# Builds and runs the project
br:
	make build
	make run

# Cleans out executable and all .o files
clean:
	rm horserace
	rm *.o
