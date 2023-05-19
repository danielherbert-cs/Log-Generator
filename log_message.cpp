//Daniel Herbert
//Class that represents a log message and contains two strings
//September 30th 2022

#include "log_message.hpp"
#include <iostream>
using namespace std;
    //Constructor of the log message class
    //Message text and timestamp are passed as parameters
    log_message::log_message(string mtext, string ts) {
        text = mtext;
        timestamp = ts;
    }
    
    //Destructor of class
    log_message::~log_message() {
    }
    
    //Method to return the actual message of the log message
    string log_message::get_message() {
        return text;
    }
 
    //Method to return timestamp of message
    string log_message::get_timestamp() {
        return timestamp;
    }

