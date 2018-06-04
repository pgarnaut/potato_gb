//
// Created by patman on 4/6/18.
//

#include "cpu.h"

CPU::CPU(Memory &mem) : mem(mem){
    this->registers = {0};

    // load boot rom
    this->opcodes[this->mem.loadb(0)]; // TODO: etc.
}

CPU::~CPU() {

}

void CPU::tick() {
    // 1 clock cycle ...

}