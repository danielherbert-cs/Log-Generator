//Daniel Herbert
//Header file for the log message class
//September 30th 2022

#ifndef log_message_hpp
#define log_message_hpp

#include <stdio.h>
#include <string>

class log_message
{
public:
    log_message(std::string mtext, std::string ts);
    ~log_message();
    std::string get_message();
    std::string get_timestamp();
    
private:
    std::string text;
    std::string timestamp;
};
#endif /* log_message_hpp */
