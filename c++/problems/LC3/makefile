CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = --std=c++11 -Wall
LDFLAGS = 
LDLIBS = 

TARGET = LC3
SRCS = LC3.cpp Memory.cpp test_LC3.cpp
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

