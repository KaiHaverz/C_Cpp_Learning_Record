#include <iostream>
#include <iomanip>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    
    // 获取某个月的天数
    int getDaysInMonth() {
        switch(month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear() ? 29 : 28;
            default:
                return 0;
        }
    }
    
public:
    // 构造函数
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    // 判断闰年
    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    // 更新到下一天
    void nextDay() {
        int maxDays = getDaysInMonth();
        
        // 如果是月末
        if (day == maxDays) {
            day = 1;
            
            // 如果是12月
            if (month == 12) {
                month = 1;
                year++;
            } else {
                month++;
            }
        } else {
            day++;
        }
    }
    
    // 格式化输出日期
    void displayDate() {
        cout << year << '-'
             << setw(2) << setfill('0') << month << '-'
             << setw(2) << setfill('0') << day << endl;
    }
};

int main() {
    int y, m, d;
    cin >> y >> m >> d;
    
    Date date(y, m, d); // 创建日期对象
    date.nextDay();      // 更新到下一天
    date.displayDate();  // 显示更新后的日期
    
    return 0;
}