
CXX=clang++
CXXFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

all: couple sim

couple: couple.o
	$(CXX) $(CXXFLAGS) -o $@ $^

sim: sim.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	/bin/rm -f ising couple sim *.o