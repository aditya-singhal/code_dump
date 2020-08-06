CC=gcc
CXX=g++
RM=rm -f
SYSTEMC_HOME=/usr/local/systemc233
CPPFLAGS = -Wall --std=c++11
LDFLAGS = -Wl,-rpath,$(SYSTEMC_HOME)/lib -L$(SYSTEMC_HOME)/lib
LDLIBS = -lsystemc

TARGET = process
SRCS = two_processes.cpp
INCLUDE = $(SYSTEMC_HOME)/include
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -I $(INCLUDE) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

