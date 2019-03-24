CXX=g++
CXX_FLAG=-g -std=c++11 -pthread

test:test.cpp threadpool.h
	${CXX} ${CXX_FLAG} -o $@ $^

PHONY:clean

clean:
	rm test