//
// Created by piyush on 19/02/22.
//

#include <iostream>
#include "Log.h"

void Log::SetLevel(Log::Level level) {
    Log::m_LogLevel = level;
}

void Log::Warn(const char *message) {
    if (Log::m_LogLevel >= Log::WarnLevel)
        std::cout << "[WARNING]:" << message << std::endl;
}

void Log::Error(const char* message){
    if (Log::m_LogLevel >= Log::ErrorLevel)
        std::cout << "[ERROR]:" << message << std::endl;
}

void Log::Info(const char* message){
    if (Log::m_LogLevel >= Log::InfoLevel)
        std::cout << "[INFO]:" << message << std::endl;
}

Log::Log() {
    std::cout << "Constructed Log instance" << std::endl;
    Log::m_LogLevel = Log::InfoLevel;
}

Log::Log(Log::Level level) {
    std::cout << "Constructed Log instance" << std::endl;
    Log::SetLevel(level);
}

Log::~Log() {
    std::cout << "Destroyed Log instance" << std::endl;
}
