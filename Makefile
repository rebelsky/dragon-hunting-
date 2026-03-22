# Makefile for a quick dragon-hunting experiment
# 
# As usual, you can build this software by typing:
#
#     make

# +----------+-------------------------------------------------------
# | Settings |
# +----------+

CXXFLAGS = -g
CXX = clang
LIBS = -std=c++20 -lstdc++ -lm
INCLUDE = 

EXECUTABLES = test-hunt trace-hunt

# +---------+--------------------------------------------------------
# | Targets |
# +---------+

default: $(EXECUTABLES)

trace-hunt: trace-hunt.o hunt.o World.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)

test-hunt: test-hunt.o hunt.o World.o
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)

clean:
	rm -f *.o $(EXECUTABLES)

# +--------------+---------------------------------------------------
# | Dependencies |
# +--------------+

World.o: World.cpp World.hpp
hunt.o: hunt.cpp hunt.hpp World.hpp
trace-hunt.o: trace-hunt.cpp hunt.hpp World.hpp
test-hunt.o: test-hunt.cpp hunt.hpp World.hpp

