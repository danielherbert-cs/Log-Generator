//Daniel Herbert
//An app to display log messages from a log
//September 30th 2022

//All include directives
#include "logger.hpp"
#include "log_message.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    //Takes name of the app as first command line argument
    logger log(argv[1]);
    //Uses the readall method to store all log messages in a vector
    vector<log_message> appLog = log.readall();
    //For loop to print all log messages with timestamps
    for (int i = 0; i < appLog.size(); i++) {
        cout <<appLog.at(i).get_message() << ": ";
        cout <<appLog.at(i).get_timestamp()<< "\n";
    }
    
    
}
