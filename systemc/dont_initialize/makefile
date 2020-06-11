CC=gcc
CXX=g++
RM=rm -f
SYSTEMC_HOME=/usr/local/systemc-2.3.3
CPPFLAGS = -Wall -std=c++11
LDFLAGS = -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -L$(SYSTEMC_HOME)/lib-linux64
LDLIBS = -lsystemc

TARGET = dont_init
SRCS = dont_initialize.cpp
INCLUDE = $(SYSTEMC_HOME)/include
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -I $(INCLUDE) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

