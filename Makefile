EXENAME = final
OBJS = main.o bfs.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm


all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp bfs.h 
	$(CXX) $(CXXFLAGS) main.cpp

bfs.o : bfs.cpp bfs.h
	$(CXX) $(CXXFLAGS) bfs.cpp

test: tests.o bfs.o 
	$(LD) tests.o bfs.o $(LDFLAGS) -o test

tests.o: tests/tests.cpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean :
	-rm -f *.o $(EXENAME) test
