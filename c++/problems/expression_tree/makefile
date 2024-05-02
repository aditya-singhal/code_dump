CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = --std=c++11 -Wall
LDFLAGS = 
LDLIBS = 

TARGET = exp_trees
SRCS = exp_trees.cpp test_exp_trees.cpp
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

