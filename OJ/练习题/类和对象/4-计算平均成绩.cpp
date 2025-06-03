#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string id;
    string name;
    int scores[3]; // 三门课程成绩

public:
    // 构造函数
    Student(string id, string name, int s1, int s2, int s3) 
        : id(id), name(name) {
        scores[0] = s1;
        scores[1] = s2;
        scores[2] = s3;
    }
    
    // 计算平均成绩
    double getAverageScore() {
        return (scores[0] + scores[1] + scores[2]) / 3.0;
    }
    
    // 显示学生信息
    void displayInfo() {
        cout << "ID: " << id << ", Name: " << name 
             << ", Average Score: " 
             << fixed << setprecision(2) << getAverageScore() << endl;
    }
};

int main() {
    int n;
    cin >> n; // 学生数量
    
    vector<Student> students;
    double totalAverage = 0; // 所有学生平均成绩的累加和
    
    for (int i = 0; i < n; i++) {
        string id, name;
        int s1, s2, s3;
        cin >> id >> name >> s1 >> s2 >> s3;
        
        // 创建学生对象
        Student student(id, name, s1, s2, s3);
        
        // 添加到向量中
        students.push_back(student);
        
        // 计算当前学生平均成绩并累加
        totalAverage += student.getAverageScore();
    }
    
    // 输出每个学生的信息
    for (Student& student : students) {
        student.displayInfo();
    }
    
    // 计算并输出总平均成绩
    double overallAverage = totalAverage / n;
    cout << "Overall Average Score: " << fixed << setprecision(2) 
         << overallAverage << endl;
    
    return 0;
}