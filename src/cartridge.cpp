#include "cartridge.h"
#include <vector>
#include <cstdio>
#include <exception>
#include <ios>
#include <iostream>


Cartridge::Cartridge(const std::string &fname) {
    this->readFile(fname);
    std::cout << "read " << this->contents.size() << " bytes from file: " << fname << std::endl;
}

void Cartridge::readFile(const std::string &fname) {
    std::FILE *fp = std::fopen(fname.c_str(), "rb");    
    if (fp) {
        std::fseek(fp, 0, SEEK_END);
        this->contents.resize(std::ftell(fp));
        std::rewind(fp);
        std::fread(&contents[0], 1, contents.size(), fp);
        std::fclose(fp);
    } else {
        throw std::ios_base::failure(std::string("kaboom opening file: ") + fname);
    }
}