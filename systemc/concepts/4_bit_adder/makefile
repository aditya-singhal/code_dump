CC=gcc
CXX=g++
RM=rm -f
SYSTEMC_HOME=/usr/local/systemc233
CPPFLAGS = -Wall
LDFLAGS = -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -L$(SYSTEMC_HOME)/lib-linux64
LDLIBS = -lsystemc

TARGET = adder
SRCS = adder.cpp bit_adder.cpp main.cpp
INCLUDE = $(SYSTEMC_HOME)/include
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -I $(INCLUDE) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

