CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
socklib.o:socklib.c
	$(CXX) $(CXXFLAGS) -g -c $< -o $@
main:main.c socklib.o
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@
server:server.c socklib.o
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@

