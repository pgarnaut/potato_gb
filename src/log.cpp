#include "log.h"


Log& Log::get(const std::string &extra, Log::Level level) {
    //static Log::Level currentLevel = 0; // Log::Level.info;
    static Log logger;
    //static Log nulllogger;
    return logger << extra;
}

//void Log::setLogLevel(Log::Level level) {
//    Log::get().currentLevel = level;
//    
//}
