//
// Created by patman on 4/6/18.
//

#include "cpu.h"
#include <iostream>

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
    //opcodes[0x00] = 
}

CPU::~CPU() {

}

void CPU::tick() {
    // 1 clock cycle ...
    Opcode opcode = this->opcodes[mem.loadb(this->registers.PC.w)];
    cout << "PC: " << hex << this->registers.PC.w << ": Opcode: " << hex << opcode.code << endl;
}