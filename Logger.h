/*
 * Author: Sharath Lokesh
 */
#pragma once

#include <cstdlib> // for std::exit()
#include <iostream>
#include <string>

enum LogLevel
{
    INFO,
    WARN,
    DEBUG
};

class Logger
{
    private:
        LogLevel _level = LogLevel::INFO;
        
        void PrintLog(LogLevel lvl, const char* msg)
        {
            const char* str;
            switch(lvl)
            {
                case LogLevel::WARN:
                    str = "WARN";
                    break;
                case LogLevel::INFO:
                    str = "INFO";
                    break;
                case LogLevel::DEBUG:
                    str = "DEBUG";
                    break;
            }
            std::cout<< str << ": " << msg << std::endl;
 
        }
        
    public:
        //constructor
        Logger(LogLevel level = LogLevel::INFO) : _level(level){}
        
        //method to set log level
        void SetLevel(char char_level)
        {
            switch(char_level)
            {
                case 'w':
                    _level = LogLevel::WARN;
                    break;
                case 'i':
                    _level = LogLevel::INFO;
                    break;
                case 'd':
                    _level = LogLevel::DEBUG;
                    break;
                default:
                    std::cerr << "Invalid log level character: " << char_level << std::endl;
            }
        }
        
        //Print Log Message
        void LogMessage(LogLevel lvl, const char* message)
        {
            if (lvl <= _level)
                PrintLog(lvl, message);
        }
        
        //Warn
        void Warn(const char* msg)
        {
            LogMessage(LogLevel::WARN, msg);
        }
        
        //INFO
        void Info(const char* msg)
        {
            LogMessage(LogLevel::INFO, msg);
        }
        
        //DEBUG
        void Debug(const char* msg)
        {
            LogMessage(LogLevel::DEBUG, msg);
        }
};