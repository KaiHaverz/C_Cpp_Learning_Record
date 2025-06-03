#include <iostream>
#include <string>
using namespace std;

// 基类：Clock
class Clock
{
protected:
    int H; // 时
    int M; // 分
    int S; // 秒

public:
    Clock() : H(0), M(0), S(0) {} // 初始时间为0时0分0秒

    // 设置时间
    void SetTime(int h, int m, int s)
    {
        H = h;
        M = m;
        S = s;
    }

    // 显示时间
    void ShowTime() const
    {
        cout << "Now:" << H << ":" << M << ":" << S << endl;
    }
};

// 派生类：AlarmClock
class AlarmClock : public Clock
{
private:
    int AH; // 闹钟时
    int AM; // 闹钟分

public:
    AlarmClock() : AH(0), AM(0) {} // 初始化闹钟时间为0时0分

    // 设置闹钟时间
    void SetAlarm(int ah, int am)
    {
        AH = ah;
        AM = am;
    }

    // 显示闹钟时间
    void ShowAlarm() const
    {
        cout << "AlarmTime:" << AH << ":" << AM << endl;
    }
};

int main()
{
    AlarmClock alarm;
    int n;
    cin >> n; // 操作数量

    while (n--)
    {
        string func;
        cin >> func;

        if (func == "SetAlarm")
        {
            int ah, am;
            cin >> ah >> am;
            alarm.SetAlarm(ah, am);
        }
        else if (func == "ShowAlarm")
        {
            alarm.ShowAlarm();
        }
        else if (func == "SetTime")
        {
            int h, m, s;
            cin >> h >> m >> s;
            alarm.SetTime(h, m, s);
        }
        else if (func == "ShowTime")
        {
            alarm.ShowTime();
        }
        else
        {
            cout << "没有这个函数！" << endl;
            // 清除当前行的剩余输入
            string dummy;
            getline(cin, dummy);
        }
    }

    return 0;
}