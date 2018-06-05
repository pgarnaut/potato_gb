#ifndef POTATO_CARTRIDGE_H
#define POTATO_CARTRIDGE_H
#include <string>
#include <vector>

class Cartridge {
public:
    Cartridge(const std::string &fname);
    virtual ~Cartridge() {}
    const std::vector<uint8_t> &data() { return this->contents; }
    
private:
    void readFile(const std::string &fname);
    std::vector<uint8_t> contents;
};

#endif
