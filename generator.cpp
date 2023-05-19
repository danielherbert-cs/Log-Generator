//Daniel Herbert
//An app that uses the logger class to generate log messages in log
//September 30th 2022

//All include directives
#include "logger.hpp"
#include "log_message.hpp"
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <signal.h>
#include <csignal>
using namespace std;

void signalHandler(int signum) {
    cout <<"Terminate signal (" <<signum<< ") received.\n";
    exit(signum);
}

int main(int argc, const char * argv[]) {
    //Creates vector to store messages passed in the command line
    vector<string> messageSet;
    //Gets the name of the app and removes the ./ from beginning
    string s = argv[0];
    int position = s.find_last_of('/');
    string newString = s.substr(position + 1);
    //Creates Generator app with logger class
    logger log(newString);
    signal(SIGINT, signalHandler);
    //Records messages passed to the log for the app
    for (int count = 1; count < argc; count++) {
        messageSet.push_back(argv[count]);
        log.write(messageSet.at(count - 1));
        //App sleeps between logging messages from between 1 and 10 seconds
        sleep(rand() % 10 + 1);
        
    }
    

}






