//
// Created by piyush on 19/02/22.
//

#ifndef HELLOWORLDCLION_LOG_H
#define HELLOWORLDCLION_LOG_H


class Log {
public:
    // this Level enum in itself isn't a namespace
    enum Level {
        ErrorLevel = 0, WarnLevel, InfoLevel
    };
private:
    Level m_LogLevel;
public:
    Log();
    Log(Level level);
    ~Log();
    void SetLevel(Level Level);
    void Warn(const char* message);
    void Error(const char* message);
    void Info(const char* message);
};


#endif //HELLOWORLDCLION_LOG_H
