CC=g++
CFLAGS=-Wall -std=c++11 -I/home/leo/cxx/gtest
CFLAGS_CO=-c
LDFLAGS=/home/leo/cxx/gtest/libgtest_main.a /home/leo/cxx/gtest/libgtest.a \
		-pthread
SRC=$(wildcard *.cc)
UNIT_SRC=$(patsubst %.cc, %_ut_.cc, $(SRC))
OBJ=$(patsubst %.cc, %.o, $(SRC))
EXECUTABLE=$(patsubst %.cc, %, $(SRC))

% : %.cc
	@echo "build "$@" with "$<
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@
#all : $(SRC) $(EXECUTABLE)
clean: 
	@rm -f $(EXECUTABLE) $(OBJ)

#$(EXECUTABLE) : $(OBJ)
#	@echo "build..."
#	$(CC) $(LDFLAGS) $< -o $@

#.cpp.o:
%.o : %.cc
	$(CC) $(CFLAGS) $(CFLAGS_CO) $< -o $@
