#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

enum class log_grade{
    info,
    error
};
class log_key
{
public:
    log_key();
    ~log_key();


    void log_record(std::string log_content,log_grade grade);


private:
    std::fstream log_file;


};


#endif // LOG_H
