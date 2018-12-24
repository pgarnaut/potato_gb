#ifndef POTATO_MOTHERBOARD_H
#define POTATO_MOTHERBOARD_H

#include <experimental/filesystem>
#include "memory.h"
#include "cpu.h"

class Motherboard {

public:
    Motherboard();
    virtual ~Motherboard();
    bool loadROM(std::experimental::filesystem::path path);
    
private:
    Memory mem;
    CPU cpu;
};

#endif // POTATO_MOTHERBOARD_H
