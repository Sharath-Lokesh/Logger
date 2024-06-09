/*
* Author: Sharath Lokesh
*/
#pragma once

#include <cstdlib> // for std::exit()
#include <iostream>
#include <string>
#include <sstream>

enum class LogLevel
{
    INFO,
    WARN,
    DEBUG
};

class Logger
{
        LogLevel _level = LogLevel::INFO;
        
        //Print Log Message

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
        explicit Logger(LogLevel level = LogLevel::INFO) : _level(level){}
        
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
        
        //INFO
        template <typename... Args>
        void Info(Args&&... args)
        {
            std::stringstream ss;
            ((ss << " " << args), ...);
            std::string formattedMsg = ss.str();

            LogMessage(LogLevel::INFO, formattedMsg.c_str());
        }

        //Warn
        template <typename... Args>
        void Warn(Args&&... args)
        {
            std::stringstream ss;
            ((ss << " " << args), ...);
            std::string formattedMsg = ss.str();

            LogMessage(LogLevel::WARN, formattedMsg.c_str());
        }
                
        //DEBUG
        template <typename... Args>
        void Debug(Args&&... args)
        {
            std::stringstream ss;
            ((ss << " " << args), ...);
            std::string formattedMsg = ss.str();

            LogMessage(LogLevel::DEBUG, formattedMsg.c_str());
        }

        //ERROR
        template <typename... Args>
        void Error(Args&&... args)
        {
            std::stringstream ss;
            ((ss << " " << args), ...);
            std::string formattedMsg = ss.str();

            std::cerr << "ERROR: " << formattedMsg << std::endl;
            std::exit(1); //Terminate the program
        }
};