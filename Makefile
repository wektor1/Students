CXX = g++
STD = 
#-std=c++14

CXXFLAGS = -Wall -Wpedantic -Wextra -std=c++14
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = student.out

.PHONY: all
all:$(TARGET)

%.o: %.cpp %.hpp 
	$(CXX) $(CXXFLAGS) $(STD) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ 

.PHONY: clean
clean:
	rm $(TARGET) $(OBJS)
