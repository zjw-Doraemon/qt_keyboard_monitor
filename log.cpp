#include "log.h"
log_key global_log;



log_key::log_key() {
    log_file.open("log.txt",std::ios::app);

}


log_key::~log_key(){
    log_file.close();

}



void log_key::log_record(std::string log_content,log_grade grade){

    // 获取当前时间点
    using namespace std::chrono;
    system_clock::time_point now(system_clock::now());

    time_t _now = system_clock::to_time_t(now);
    tm format_now;
    localtime_s(&format_now, &_now);
    // 用于存储格式化后的时间字符串
    char buffer[100];

    // 格式化时间
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &format_now);
    std::string grade_log;
    switch (grade)
{
    case log_grade::info:
        grade_log="info";
        break;

    case log_grade::error:
        grade_log="error";
        break;

}

    log_file<<buffer<<"  "<<log_content<<"  "<<grade_log<<"\n" ;


}
