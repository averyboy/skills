CXX=g++
CXX_FLAGS=-pthread -g

test:test.cpp threadpool.o
	${CXX} ${CXX_FLAGS} -o $@ $^

threadpool.o:threadpool.cpp
	${CXX} -c -g $^

PHONY:clean

clean:
	rm *.o test