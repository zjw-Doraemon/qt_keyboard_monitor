#ifndef KEYBOARD_MONITOR_H
#define KEYBOARD_MONITOR_H
#include <iostream>
#include <windows.h>
#include <string>
#include <QObject>
#include <QDebug>
class keyboard_monitor:public QObject
{
    Q_OBJECT
public:
    keyboard_monitor();
    ~keyboard_monitor();
    void start();
    void stop();
    static LRESULT CALLBACK key_board_record(int nCode, WPARAM wParam, LPARAM lParam);
    static std::string  GetKeyName(DWORD &vkCode);



private:
    HHOOK hook ;




signals:
    void send_message(std::string);

private:
    static keyboard_monitor* instance;

};

#endif // KEYBOARD_MONITOR_H








