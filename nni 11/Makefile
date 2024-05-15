CXX = g++

CXXFLAGS = -std=c++17 -pedantic -Wall -Wconversion -Werror
LDFLAGS = -lglut -lGL -lGLU

main: main.o 
	$(CXX) $(CXXFLAGS) -o main main.o $(LDFLAGS)

main.o: riana.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

check: main
	./main

clean:
	rm -f *.o main

