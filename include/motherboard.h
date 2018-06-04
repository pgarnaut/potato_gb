#ifndef POTATO_MOTHERBOARD_H
#define POTATO_MOTHERBOARD_H

#include "memory.h"
#include "cpu.h"

class Motherboard {

public:
    Motherboard();
    virtual ~Motherboard();

private:
    Memory mem;
    CPU cpu;
};

#endif // POTATO_MOTHERBOARD_H