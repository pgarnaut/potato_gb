#ifndef POTATO_LOG_H
#define POTATO_LOG_H

// holy crap it's tricky implementing log levels with a stream-based templated logging class... 
// should come back to this interesting puzzle.. or maybe someone else has solved this already?

#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

// only other way to do this, and have it transparent to the log user would be to
// make use of GNU backtrace(), which is doable
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define LOG_CRAP __FILE__ "(" TOSTRING(__LINE__) ") "

class Log {
private:
    // can't be forward declared
    using endl_type = std::ostream&(std::ostream&);
    enum Level {spam=0, info=1, debug=2, warning=3, error=4}; // TODO: <--- one day...
    
public:    
    Log& operator<<(endl_type endl){
        _next_is_begin = true;
        fprintf(stdout, "%s\n", logbuf.str().c_str());
        logbuf.str(std::string());
        return *this;
    }

    template<typename T>
    Log& operator<< (const T& data){
        logbuf << data;
        _next_is_begin = false;
        return *this;
    }

    static Log& get(const std::string &extra = "", Log::Level level = Log::Level::info);
    
    //static void setLogLevel(Log::Level level);
    
    
private:
    bool _next_is_begin;
    std::stringstream logbuf;
    Log::Level currentLevel;
    //static Log logger;
};

#endif //POTATO_LOG_H
