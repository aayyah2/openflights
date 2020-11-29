EXENAME = final
OBJS = main.o BFS.o other.o graph.o random.o edge.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm


all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp BFS.h other.h  edge.h graph.h random.h
	$(CXX) $(CXXFLAGS) main.cpp

BFS.o : BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

graph.o : graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

random.o : random.cpp random.h
	$(CXX) $(CXXFLAGS) random.cpp

edge.o : edge.h 
	$(CXX) $(CXXFLAGS) edge.h

other.o : other.cpp other.h
	$(CXX) $(CXXFLAGS) other.cpp

test: test.o BFS.o 
	$(LD) test.o BFS.o $(LDFLAGS) -o test

tests.o: tests/test.cpp
	$(CXX) $(CXXFLAGS) tests/test.cpp

catchmain.o : catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

clean :
	-rm -f *.o $(EXENAME) test
