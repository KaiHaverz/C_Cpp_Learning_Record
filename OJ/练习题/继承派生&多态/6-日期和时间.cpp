#include <iostream>
#include <string>
using namespace std;

// 月份天数数组（索引1-12）
const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某个月份的天数
int getDaysInMonth(int year, int month) {
    if (month == 2 && isLeapYear(year)) 
        return 29;
    return daysPerMonth[month];
}

// 基类：时间
class Time {
protected:
    int Hours;    // 时
    int Minutes;  // 分
    int Seconds;  // 秒
    
public:
    // 默认构造函数（0:0:0）
    Time() : Hours(0), Minutes(0), Seconds(0) {}
    
    // 设置时间
    void SetTime(int h, int m, int s) {
        Hours = h;
        Minutes = m;
        Seconds = s;
    }
    
    // 输出时间
    void PrintTime() const {
        cout << Hours << ":" << Minutes << ":" << Seconds;
    }
};

// 基类：日期
class Date {
protected:
    int Year;   // 年
    int Month;  // 月
    int Day;    // 日
    
public:
    // 默认构造函数（1/1/1）
    Date() : Year(1), Month(1), Day(1) {}
    
    // 设置日期
    void SetDate(int y, int m, int d) {
        Year = y;
        Month = m;
        Day = d;
    }
    
    // 输出日期
    void PrintDate() const {
        cout << Year << "/" << Month << "/" << Day;
    }
};

// 派生类：日期时间（继承自Date和Time）
class DateTime : public Date, public Time {
public:
    // 增加秒数
    void incrementSeconds(int s) {
        // 增加秒数
        Seconds += s;
        
        // 处理秒进位到分
        int carryMinutes = Seconds / 60;
        Seconds %= 60;
        Minutes += carryMinutes;
        
        // 处理分进位到时
        int carryHours = Minutes / 60;
        Minutes %= 60;
        Hours += carryHours;
        
        // 处理时进位到天
        int carryDays = Hours / 24;
        Hours %= 24;
        
        // 增加天数
        if (carryDays > 0) {
            addDays(carryDays);
        }
    }
    
    // 输出日期时间
    void PrintDateTime() const {
        PrintDate();
        cout << " ";
        PrintTime();
        cout << endl;
    }
    
private:
    // 增加天数
    void addDays(int days) {
        for (int i = 0; i < days; i++) {
            Day++;
            
            // 检查是否超过当前月份的天数
            int maxDays = getDaysInMonth(Year, Month);
            if (Day > maxDays) {
                Day = 1;
                Month++;
                
                // 检查是否超过12月
                if (Month > 12) {
                    Month = 1;
                    Year++;
                }
            }
        }
    }
};

int main() {
    DateTime dt;
    int n;
    cin >> n; // 操作数量
    
    while (n--) {
        string func;
        cin >> func;
        
        if (func == "PrintDateTime") {
            dt.PrintDateTime();
        }
        else if (func == "incrementSeconds") {
            int s;
            cin >> s;
            dt.incrementSeconds(s);
        }
        else if (func == "SetTime") {
            int h, m, s;
            cin >> h >> m >> s;
            dt.SetTime(h, m, s);
        }
        else if (func == "SetDate") {
            int y, m, d;
            cin >> y >> m >> d;
            dt.SetDate(y, m, d);
        }
        else if (func == "PrintDate") {
            dt.PrintDate();
            cout << endl;
        }
        else if (func == "PrintTime") {
            dt.PrintTime();
            cout << endl;
        }
        else {
            cout << "没有这个函数！" << endl;
            // 清除当前行剩余输入
            string dummy;
            getline(cin, dummy);
        }
    }
    
    return 0;
}