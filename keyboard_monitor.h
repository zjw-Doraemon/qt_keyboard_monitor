#ifndef KEYBOARD_MONITOR_H
#define KEYBOARD_MONITOR_H
#include <iostream>
#include <windows.h>
#include <string>
#include <QObject>
#include <QDebug>
#include <fstream>
#include <vector>
#include <QCloseEvent>
class keyboard_monitor:public QObject
{
    Q_OBJECT
public:
    keyboard_monitor();
    ~keyboard_monitor();
    void start();
    void stop();
    //钩子函数
    static LRESULT CALLBACK key_board_record(int nCode, WPARAM wParam, LPARAM lParam);
    //获取键的字符串
    static std::string  GetKeyName(DWORD &vkCode);
    //存储键位历史文件
    static void save_csv(std::vector<std::string>  csv_string);



private:
    HHOOK hook ;
    static std::fstream csv_keyboard;






signals:
    void send_message(std::string);

private:
    static keyboard_monitor* instance;

};

#endif // KEYBOARD_MONITOR_H








