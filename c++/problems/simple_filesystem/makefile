CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = --std=c++11 -Wall
LDFLAGS = 
LDLIBS = 

TARGET = file_system
SRCS = file_system.cpp test_file_system.cpp
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

