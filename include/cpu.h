//
// Created by patman on 4/6/18.
//

#ifndef POTATO_CPU_H
#define POTATO_CPU_H

#include <string>
#include <vector>
#include "memory.h"

class CPU {
public:
    CPU(Memory &mem);
    virtual ~CPU();
    void tick();

    // base class for all opcodes
    class Opcode {
    public:
        // default is NOP opcode
        Opcode(uint8_t code = 0x00, uint8_t cycles = 4, const std::string &mnemonic = "NOP") { }

        // hmm confused myself with the copy/move operators
        //Opcode(const Opcode& o) : code(o.code), cycles(o.cycles), mnemonic(o.mnemonic) { }
        //Opcode(Opcode&& o) noexcept : mnemonic(std::move(o.mnemonic)) {}
        uint8_t code, cycles;
        std::string mnemonic;

        uint8_t execute() { return cycles; } // return # of cycles taken
    };


private:
    Memory &mem;
    std::vector<Opcode> opcodes;

    union Register {
        uint16_t w;
        struct {
            uint8_t b1;
            uint8_t b0;
        };
    };

    struct RegisterBank {
        Register AF, BC, DE, HL, SP, PC;
    } registers;

    uint8_t &A = registers.AF.b0;
    uint8_t &F = registers.AF.b1;
    // etc

    // struct Registers {
    //     uint8_t A,F,B,C,D,E,H,L;
    //     uint16_t SP, PC;
    // } registers;
};


#endif //POTATO_CPU_H
