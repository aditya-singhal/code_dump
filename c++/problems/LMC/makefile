CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = --std=c++11 -Wall
LDFLAGS = 
LDLIBS = 

TARGET = LMC
SRCS = LMC.cpp Memory.cpp test_LMC.cpp
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

