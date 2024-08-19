#include "keyboard_monitor.h"


keyboard_monitor*keyboard_monitor:: instance = nullptr;



keyboard_monitor::keyboard_monitor() 
{

}
keyboard_monitor::~keyboard_monitor()
{

}



    // 定义钩子过程
LRESULT CALLBACK keyboard_monitor:: key_board_record(int nCode, WPARAM wParam, LPARAM lParam) {

        if (nCode >=0) {
            if (wParam == WM_KEYDOWN) {
                PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
                DWORD vkCode = p->vkCode;
                // 获取按键对应的字符
                std::string key = GetKeyName(vkCode);

                // 获取按键的时间戳
                auto now = std::chrono::system_clock::now();
                std::time_t time = std::chrono::system_clock::to_time_t(now);

                // 将字符和时间组合成一个字符串
                std::string message = key + " pressed at   " + std::ctime(&time);

                // 发送组合后的信息
                emit instance->send_message(message);





            }
        }
        return 0;
    }


    void keyboard_monitor::stop(){

        UnhookWindowsHookEx(hook);
        hook = nullptr;
        instance = nullptr;  // 清除静态指针

    }
    void keyboard_monitor::start(){

        instance=this;
        hook = SetWindowsHookExA(WH_KEYBOARD_LL,keyboard_monitor:: key_board_record, NULL, 0);
        if (hook == NULL) {
            std::cout << "Failed to set hook!" << std::endl;
        }


    }



    std::string keyboard_monitor:: GetKeyName(DWORD &vkCode) {

        switch (vkCode) {
        case VK_ESCAPE: return "Esc";
        case VK_RETURN: return "Enter";
        case VK_SPACE: return "Space";
        case VK_SHIFT: return "Shift";
        case VK_CONTROL: return "Ctrl";
        case VK_MENU: return "Alt";
        case VK_BACK: return "Backspace";
        case VK_TAB: return "Tab";
        case VK_CAPITAL: return "Caps Lock";
        case VK_LSHIFT: return "Left Shift";
        case VK_RSHIFT: return "Right Shift";
        case VK_LCONTROL: return "Left Ctrl";
        case VK_RCONTROL: return "Right Ctrl";
        case VK_LMENU: return "Left Alt";
        case VK_RMENU: return "Right Alt";
        case VK_INSERT: return "Insert";
        case VK_DELETE: return "Delete";
        case VK_HOME: return "Home";
        case VK_END: return "End";
        case VK_PRIOR: return "Page Up";
        case VK_NEXT: return "Page Down";
        case VK_LEFT: return "Left Arrow";
        case VK_RIGHT: return "Right Arrow";
        case VK_UP: return "Up Arrow";
        case VK_DOWN: return "Down Arrow";
        case VK_NUMLOCK: return "Num Lock";
        case VK_SCROLL: return "Scroll Lock";
        case VK_PAUSE: return "Pause";
        case VK_SNAPSHOT: return "Print Screen";
        case VK_F1: return "F1";
        case VK_F2: return "F2";
        case VK_F3: return "F3";
        case VK_F4: return "F4";
        case VK_F5: return "F5";
        case VK_F6: return "F6";
        case VK_F7: return "F7";
        case VK_F8: return "F8";
        case VK_F9: return "F9";
        case VK_F10: return "F10";
        case VK_F11: return "F11";
        case VK_F12: return "F12";
        case VK_LWIN: return "Left Windows";
        case VK_RWIN: return "Right Windows";
        case VK_APPS: return "Applications";
        case VK_SLEEP: return "Sleep";
        case VK_NUMPAD0: return "Numpad 0";
        case VK_NUMPAD1: return "Numpad 1";
        case VK_NUMPAD2: return "Numpad 2";
        case VK_NUMPAD3: return "Numpad 3";
        case VK_NUMPAD4: return "Numpad 4";
        case VK_NUMPAD5: return "Numpad 5";
        case VK_NUMPAD6: return "Numpad 6";
        case VK_NUMPAD7: return "Numpad 7";
        case VK_NUMPAD8: return "Numpad 8";
        case VK_NUMPAD9: return "Numpad 9";
        case VK_MULTIPLY: return "Numpad *";
        case VK_ADD: return "Numpad +";
        case VK_SEPARATOR: return "Numpad Separator";
        case VK_SUBTRACT: return "Numpad -";
        case VK_DECIMAL: return "Numpad .";
        case VK_DIVIDE: return "Numpad /";
        case VK_BROWSER_BACK: return "Browser Back";
        case VK_BROWSER_FORWARD: return "Browser Forward";
        case VK_BROWSER_REFRESH: return "Browser Refresh";
        case VK_BROWSER_STOP: return "Browser Stop";
        case VK_BROWSER_SEARCH: return "Browser Search";
        case VK_BROWSER_FAVORITES: return "Browser Favorites";
        case VK_BROWSER_HOME: return "Browser Home";
        case VK_VOLUME_MUTE: return "Volume Mute";
        case VK_VOLUME_DOWN: return "Volume Down";
        case VK_VOLUME_UP: return "Volume Up";
        case VK_MEDIA_NEXT_TRACK: return "Next Track";
        case VK_MEDIA_PREV_TRACK: return "Previous Track";
        case VK_MEDIA_STOP: return "Stop";
        case VK_MEDIA_PLAY_PAUSE: return "Play/Pause";
        case VK_LAUNCH_MAIL: return "Launch Mail";
        case VK_LAUNCH_MEDIA_SELECT: return "Launch Media Select";
        case VK_LAUNCH_APP1: return "Launch App1";
        case VK_LAUNCH_APP2: return "Launch App2";
        // 添加其他特殊键的处理
        default: {
            char key = MapVirtualKey(vkCode, MAPVK_VK_TO_CHAR);
            return std::string(1, key);
        }
        }


    }
