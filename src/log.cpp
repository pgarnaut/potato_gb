#include "log.h"


Log& Log::get(const std::string &extra) {
    static Log logger;
    return logger << extra;
}