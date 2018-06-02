#include <iostream>
#include "motherboard.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "start" << endl;
    
    Motherboard mobo;



    // here's a quick example of endinaness, because i still manage to confuse myself sometimes :(
    uint8_t b1 = 0x0F;
    uint8_t b2 = 0x0A;

    uint16_t w1=0, w2=0;

    // addr    =  456 457
    // contents = 0F  0A
    // value =  0F0A

    w1 = ((b1 | w1) << 8) | b2;
    w2 = ((b2 | (uint16_t)0) << 8) | b1;

    uint8_t buf[2] = {0x0F, 0x0A};


    cout << hex << "big endian: " << w1 << endl;
    cout << hex << "little endian: " << w2 << endl;
    cout << hex << "system endianness: " << *(uint16_t *)buf << endl;

    cout << "end" << endl;
    return 0;
}