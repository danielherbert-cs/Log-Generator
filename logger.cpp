//Daniel Herbert
//A simple logger class that contains a constructor,
//a destructor, write method and read all method
//September 30th 2022

#include "logger.hpp"
#include <iostream>
using namespace std;
    //Constructor for the Logger class
    //Name of the app is passed 
    logger::logger(string app) {
        transform(app.begin(), app.end(), app.begin(), ::toupper);
        appName = app;
        //cout <<appName;
        char *zErrMsg = 0;
        int open;
        int rc;
        //SQL statement to create a table in the database if it does not exist
        string query = "create table if not exists " + appName + " (timestamp varchar(255), message varchar(255));";
        const char *sql = query.c_str();
        //open = sqlite3_open("/Users/danielherbert/database.db", &db);
        //Opening a new database connection
        open = sqlite3_open("database.db", &db);
        //Print statements for whether or not database was successfully opened
        if (open) {
            printf("Can't open database\n");
        }
        else {
            printf("Database opened succesfully\n");
        }
        
        //Creating a table in database
        rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
        //Print statements for whether or not table was successfully created in database
        if (rc != SQLITE_OK) {
            cout << "Error creating table";
        } else {
            cout << "Table created successfully\n";
        }
        
        }
        
        //Destructor for when logging is done
        logger::~logger() {
            int closed = sqlite3_close(db);
            
            if (closed) {
                printf("Can't close database\n");
            }
            else {
                printf("Database closed succesfully\n");
            }
        }
    
        //Write method that records message text to log for the app
        //Does not return anything
        void logger::write(string logMessage) {
            int rc;
            //Getting timestamp for when write() is called
            time_t now = time(0);
            string date = ctime(&now);
            date = date.erase(date.length()-1);
            //SQL statement for inserting into table
            string query = "insert into " + appName + " values (\""+ date +  "\" , \"" + logMessage + "\");";
            cout <<query;
            const char *sql = query.c_str();
            char *zErrMsg = 0;
            //Inserting message into table
            rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
            //Print statements for whether or not message was successfully inserted into the table
            if (rc != SQLITE_OK) {
                cout << "Error inserting records\n";
            } else {
                cout << "Records inserted successfully\n";
            }
        }
    
        //Method to return vector that contains all messages logged in the app
        vector<log_message> logger::readall() {
            //Creating an empty vector
            vector <log_message> messageLog;
            //SQL statement to retrieve messages for the app
            string query = "select * from " + appName + ";";
            sqlite3_stmt* stmt;
            const char *sql = query.c_str();
            int len = strlen(sql);
            int ret = sqlite3_prepare_v2(db, sql, len, &stmt, NULL);
            if (ret != SQLITE_OK) {
                cout << "Error preparing statement records\n";
            }
            int r = sqlite3_step(stmt);
            //While loop that inserts messages into vector as long as there are still messages
            while (r == SQLITE_ROW) {
                string messageCol1 = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
                string messageCol2 = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
                log_message log(messageCol1, messageCol2);
                messageLog.push_back(log);
                r = sqlite3_step(stmt);
            }
            sqlite3_finalize(stmt);
            //Returns vector
            return messageLog;
        }
    
    

