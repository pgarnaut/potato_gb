//
// Created by patman on 4/6/18.
//

#include "cpu.h"
#include "log.h"
#include <iostream>
#include <string_view>
#include "json.hpp"

using namespace std;

CPU::CPU(Memory &mem) : mem(mem) {
    this->registers = {{0}};

    // always 256 opcodes, with one being a prefix to another 256
    //opcodes.resize(512);
    //std::fill(opcodes.begin(), opcodes.end(), Opcode()); //this->opcodes.insert(512);
    opcodes.assign(512, Opcode());
    for (size_t i=0; i<opcodes.size(); i++) {
        opcodes[i].code = i;
    }

    Opcode ld_sp = opcodes[0x31];
    opcodes[0x31] = Opcode(0x31, 12, "LD");
    

    //opcodes[0x31] = Opcode({1,2,""});

}

CPU::~CPU() {

}

void CPU::tick() {
    // 1 clock cycle ...
    Opcode opcode = this->opcodes[mem.loadb(registers.PC.w)];
    registers.PC.w++;
    Log::get(LOG_CRAP) << "PC: " << hex << this->registers.PC.w << ": Opcode: " 
            << hex << opcode.code
            << " " << opcode.mnemonic << endl;
    
    uint8_t cycles = opcode.execute();

    // do something with cycles... 
}
