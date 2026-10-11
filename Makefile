CXX = g++
CXXFLAGS = -std=c++14 -O2

all: code

code: main.cpp
	$(CXX) $(CXXFLAGS) -o code main.cpp

clean:
	rm -f code

