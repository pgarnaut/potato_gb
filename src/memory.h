//#include <cstdint>
#include <stdint.h>

class Memory {
public:
    Memory();
    virtual ~Memory();

private:
    uint8_t *mem;
};