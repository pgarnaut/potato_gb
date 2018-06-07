#ifndef POTATO_LOG_H
#define POTATO_LOG_H

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
    enum Level {debug=0, information=1, warning=2, error=3};
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

    static Log& get(const std::string &extra = "");

private:
    bool _next_is_begin;
    std::stringstream logbuf;
};

#endif //POTATO_LOG_H
