CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = --std=c++11 -Wall
LDFLAGS = 
LDLIBS = 

TARGET = simple_list
SRCS = simple_list.cpp test_simple_list.cpp
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

