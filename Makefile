CXX=clang++
# CXX=g++


CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=lab04Test

all: ${BINARIES}

lab04Test: lab04Test.o lab04Test.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
