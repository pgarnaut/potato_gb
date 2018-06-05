#include "motherboard.h"
#include "cartridge.h"
// cpu
// gpu
// etc

Motherboard::Motherboard() : mem(32*1024), cpu(mem) {
    // load boot rom image into memory just for fun
    // start CPU on first instruction

    
    // read rom into memory... inefficient way to do it but its nice and clear this way...
    // might change to just read directly into memory instead
    mem.loadImage(Cartridge("../images/BOOT_ROM.bin").data());
    while(true) {
        cpu.tick();
        // break when it HALTs or something?
        break;
    }

    // now load an actual game ROM in the same manner ...

}

Motherboard::~Motherboard() {

}