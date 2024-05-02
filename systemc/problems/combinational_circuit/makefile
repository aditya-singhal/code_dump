CC=gcc
CXX=g++
RM=rm -f
# SYSTEMC_HOME=/usr/local/systemc-2.3.3
CPPFLAGS = -Wall
LDFLAGS = -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -L$(SYSTEMC_HOME)/lib-linux64
LDLIBS = -lsystemc

TARGET = circuit
SRCS = AndGate.cpp OrGate.cpp NotGate.cpp hm.cpp hm_test.cpp test_circuit.cpp
INCLUDE = $(SYSTEMC_HOME)/include
OBJS = $(subst .cc,.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -I $(INCLUDE) -o $(TARGET) $(OBJS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(RM) $(TARGET)

