EXENAME = final
OBJS = main.o BFS.o other.o edge.o graph.o Dijkstra.o LandmarkPath.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic 
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm


all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

BFS.o : BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

Dijkstra.o : Dijkstra.cpp Dijkstra.h
	$(CXX) $(CXXFLAGS) Dijkstra.cpp

LandmarkPath.o : LandmarkPath.cpp LandmarkPath.h
	$(CXX) $(CXXFLAGS) LandmarkPath.cpp

other.o : other.cpp other.h
	$(CXX) $(CXXFLAGS) other.cpp

edge.o : edge.cpp
	$(CXX) $(CXXFLAGS) edge.cpp

graph.o : graph.cpp graph.h edge.o 
	$(CXX) $(CXXFLAGS) graph.cpp

test: test.o catchmain.o other.o graph.o Dijkstra.o LandmarkPath.o BFS.o
	$(LD) catchmain.o test.o other.o graph.o Dijkstra.o LandmarkPath.o BFS.o $(LDFLAGS) -o test

catchmain.o : catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

test.o: tests/test.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) tests/test.cpp

main.o : main.cpp BFS.h other.h graph.h Dijkstra.h LandmarkPath.h
	$(CXX) $(CXXFLAGS) main.cpp

clean :
	-rm -f *.o $(EXENAME) test