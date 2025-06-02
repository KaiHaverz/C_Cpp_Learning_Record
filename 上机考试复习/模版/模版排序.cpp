#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <numeric>
using namespace std;

template <typename T>
class Grader
{
    T *SoccerArr;
    int len;

public:
    ~Grader()
    {
        delete[] ScoreArr;
    }

    Grader(T a[], int count)
    {
        len = count;
        ScoreArr = new T[len];
        for (int i = 0; i < len; ++i)
        {
            ScoreArr[i] = a[i];
        }
    }

    void sortAndShow()
    {
        sort(ScoreArr, ScoreArr + len);
        for (int i = 0; i < len; ++i)
        {
            cout << ScoreArr[i];
            if (i != len - 1)
                cout << " ";
        }
        cout << endl;
    }

    T avgScore()
    {
        if (len == 0)
            return T(); // 处理空数组情况

        if (typeid(T) == typeid(char))
        {
            // 处理char类型
            int sum = 0;
            for (int i = 0; i < len; ++i)
            {
                sum += (90 - (ScoreArr[i] - 'A') * 10); // A=90, B=80, etc.
            }

            if (len < 3)
            {
                int avg = sum / len;
                return static_cast<T>('A' + (9 - avg / 10));
            }
            else
            {
                // 去掉最高分和最低分（已排序）
                sum -= (90 - (ScoreArr[0] - 'A') * 10);       // 最低分
                sum -= (90 - (ScoreArr[len - 1] - 'A') * 10); // 最高分
                int avg = sum / (len - 2);
                return static_cast<T>('A' + (9 - avg / 10));
            }
        }
        else
        {
            // 处理int和double类型
            if (len < 3)
            {
                T sum = accumulate(ScoreArr, ScoreArr + len, T(0));
                return sum / len;
            }
            else
            {
                // 去掉最高分和最低分（已排序）
                T sum = accumulate(ScoreArr + 1, ScoreArr + len - 1, T(0));
                return sum / (len - 2);
            }
        }
    }
};