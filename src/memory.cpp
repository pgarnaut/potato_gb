#include "memory.h"

Memory::Memory(size_t size) : mem(size) {

}

Memory::~Memory() {
    
}

// load byte
uint8_t Memory::loadb(uintptr_t addr) {
    assert(addr + 1 < this->mem.size());
    
    return this->mem[addr];
}

// load word (return in little endian order)
uint16_t Memory::loadw(uintptr_t addr) {
    assert(addr + 2 < this->mem.size());

    return ((this->mem[addr + 1] | (uint16_t)0) << 8) | this->mem[addr];
}

void Memory::fill(uintptr_t start, uintptr_t end, uint8_t value) {
    assert(end > start);
    assert(start > 0);
    assert(end + 1 < this->mem.size());
    
    // TODO: c++11 insert() might be better?
    memset(&this->mem[start], end - start, value);
}