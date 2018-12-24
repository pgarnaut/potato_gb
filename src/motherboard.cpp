#include "motherboard.h"
#include "cartridge.h"
#include <iostream>
#include <string>
#include <system_error>
// cpu
// gpu
// etc

Motherboard::Motherboard() : mem(32*1024), cpu(mem) {
    // load boot rom image into memory just for fun
    // start CPU on first instruction

    
    // read rom into memory... inefficient way to do it but its nice and clear this way...
    // might change to just read directly into memory instead
    
    while(true) {
        cpu.tick();
        // break when it HALTs or something?
        break;
    }

    // now load an actual game ROM in the same manner ...

}

bool Motherboard::loadROM(std::experimental::filesystem::path path) {
    std::cout << "loading ROM: " << path << std:: endl;
    
    // where is "No such file or directory", i.e. error code #2 defined??
    if (!std::experimental::filesystem::exists(path))
        throw std::experimental::filesystem::filesystem_error("ROM does not exist", 
                                            std::make_error_code(static_cast<std::errc>(2)));
        
    mem.loadImage(Cartridge(path).data());
    return true;
}



Motherboard::~Motherboard() {

}
