//
// Created by patman on 4/6/18.
//

#ifndef POTATO_CPU_H
#define POTATO_CPU_H

#include <vector>
#include "memory.h"

class CPU {
public:
    CPU(Memory &mem);
    virtual ~CPU();
    void tick();

    class Opcode {
    };


private:
    Memory &mem;
    std::vector<Opcode> opcodes;

    struct Registers {
        uint8_t A,F,B,C,D,E,H,L;
        uint16_t SP, PC;
    } registers;
};


#endif //POTATO_CPU_H
