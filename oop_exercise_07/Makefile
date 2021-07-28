CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wextra -Wall -Werror -Wno-sign-compare -Wno-unused-result -pedantic
FILES = main.cpp 
NAME = oop_exercise_07

all: main.o

main.o:
	$(CXX) $(CXXFLAGS) -o $(NAME) $(FILES)

clean:
	rm -f *.o $(NAME)