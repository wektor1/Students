CXX = g++
STD = -std=c++14
CXXFLAGS = -Wall -Wpedantic -Wextra
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = hello.out

.PHONY: all
all:$(TARGET)

%.o: %.cpp %.hpp 
	$(CXX) $(CXXFLAGS) $(STD) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ 
	./hello.out

.PHONY: clean
clean:
	rm $(TARGET) $(OBJS)
