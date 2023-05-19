//Daniel Herbert
//Header file for the logger class
//September 30th 2022

#ifndef logger_hpp
#define logger_hpp

#include <stdio.h>
#include <sqlite3.h>
#include <chrono>
#include "log_message.hpp"
#include <vector>
#include <string>


class logger
{
public:
    logger(std::string app);
    ~logger();
    void write(std::string logMessage);
    std::vector<log_message> readall();

private:
    std::string appName;
    sqlite3 *db;
};

#endif /* logger_hpp */
