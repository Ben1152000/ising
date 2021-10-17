
CXX=clang++
CXXFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
OBJ = ising.o

ising: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	/bin/rm -f ising *.o