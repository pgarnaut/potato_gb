// NOTES:
//  the use of uintptr_t instead of just a uint16_t or something seems overkill for an 8bit emulator :D
#include <stdint.h>
#include <stddef.h>
#include <vector>

class Memory {
public:
    Memory(size_t size = 0);
    virtual ~Memory();

    // load byte
    uint8_t loadb(uintptr_t addr);

    // load word (return in little endian order)
    uint16_t loadw(uintptr_t addr);

private:
    void fill(uintptr_t start, uintptr_t end, uint8_t value = 0);

    std::vector<uint8_t> mem;
};