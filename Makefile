EXENAME = final
OBJS = main.o BFS.o other.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm


all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp BFS.h other.h
	$(CXX) $(CXXFLAGS) main.cpp

BFS.o : BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp

other.o : other.cpp other.h
	$(CXX) $(CXXFLAGS) other.cpp

test: tests.o BFS.o 
	$(LD) tests.o BFS.o $(LDFLAGS) -o test

tests.o: tests/tests.cpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean :
	-rm -f *.o $(EXENAME) test
