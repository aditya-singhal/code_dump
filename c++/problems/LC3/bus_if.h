#ifndef __BUS_IF_H__
#define __BUS_IF_H__

#include <iostream>
#include <stdint.h>

class bus_if {
public:
	typedef enum {BUS_OK, BUS_ERROR} status_t;
 	virtual status_t read(uint16_t addr, uint16_t &data) = 0;
	virtual status_t write(uint16_t addr, uint16_t data) = 0;
};

#endif