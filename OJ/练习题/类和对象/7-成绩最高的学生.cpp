#include <iostream>
using namespace std;

class Student
{
private:
    int id;
    int score;

public:
    void setData(int i, int s)
    {
        id = i;
        score = s;
    }

    int getId() { return id; }
    int getScore() { return score; }
};

void max(Student *students, int size)
{
    // 找出最高分
    int highestScore = 0;
    for (int i = 0; i < size; i++)
    {
        if (students[i].getScore() > highestScore)
        {
            highestScore = students[i].getScore();
        }
    }

    // 创建临时数组存储所有最高分学生
    Student highestStudents[4];
    int count = 0;

    // 收集所有最高分学生
    for (int i = 0; i < size; i++)
    {
        if (students[i].getScore() == highestScore)
        {
            highestStudents[count] = students[i];
            count++;
        }
    }

    // 按学号排序最高分学生
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (highestStudents[j].getId() > highestStudents[j + 1].getId())
            {
                // 交换学生信息
                Student temp = highestStudents[j];
                highestStudents[j] = highestStudents[j + 1];
                highestStudents[j + 1] = temp;
            }
        }
    }

    // 输出最高分学生的学号和成绩
    for (int i = 0; i < count; i++)
    {
        cout << highestStudents[i].getId() << " "
             << highestStudents[i].getScore() << endl;
    }
}

int main()
{
    Student students[4]; // 4个学生的数组

    // 读入学生数据
    for (int i = 0; i < 4; i++)
    {
        int id, score;
        cin >> id >> score;
        students[i].setData(id, score);
    }

    // 调用max函数，传入指向学生数组的指针
    max(students, 4);

    return 0;
}