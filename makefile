CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
main:main.c
	$(CXX) $(CXXFLAGS) -g -O $< -o $@

