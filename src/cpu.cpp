//
// Created by patman on 4/6/18.
//

#include "cpu.h"
#include "log.h"
#include <iostream>
#include <fstream>
#include <string_view>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;
namespace fs = std::experimental::filesystem;

CPU::CPU(Memory &mem, fs::path opcodesFile) : mem(mem) {
    this->loadOpcodes(opcodesFile);
    this->registers = {{0}};

//     
//     opcodes.resize(512);
//     cout << " new size: " << this->opcodes.size() << endl;
//     //std::fill(opcodes.begin(), opcodes.end(), Opcode()); //this->opcodes.insert(512);
//     opcodes.assign(512, Opcode());
//     for (size_t i=0; i<opcodes.size(); i++) {
//         opcodes[i].code = i;
//     }
// 
//     Opcode ld_sp = opcodes[0x31];
//     opcodes[0x31] = Opcode(0x31, 12, "LD");
//     

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



int CPU::loadOpcodes(std::experimental::filesystem::path opcodesFile) {
    // always (at most) 256 opcodes, with one being a prefix to another 256
    this->opcodes.resize(512);
    ifstream(opcodesFile) >> opcodeTable;
    
    Log::get(LOG_CRAP) << "read " << opcodeTable["unprefixed"].size() << " unprefixed opcodes" << endl;
    Log::get(LOG_CRAP) << "read " << opcodeTable["cbprefixed"].size() << " CB prefixed opcodes" << endl;
    
    for (json::iterator op = opcodeTable["unprefixed"].begin(); op != opcodeTable["unprefixed"].end(); ++op) {
        // look away now
        uint8_t code = strtoul(string(op.key()).c_str(), nullptr, 16) % 256; 
        
        Log::get(LOG_CRAP) << "code: " <<  std::uppercase << std::setfill('0') << std::setw(2) << std::hex << code << " mnemonic: " << op.value()["mnemonic"] << endl;
        opcodes[code] = Opcode(
            code, 
            op.value()["cycles"][0], // json file has a weird format...
            op.value()["mnemonic"]);
    }
    
    return opcodeTable["unprefixed"].size() + opcodeTable["cbprefixed"].size();
}

