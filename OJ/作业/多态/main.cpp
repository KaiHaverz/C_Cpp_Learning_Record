#include <iostream>
#include <cmath>
using namespace std;

// 基类Distance
class Distance {
protected:
    int x1, y1, x2, y2; // 两个点的坐标

public:
    // 构造函数初始化坐标
    Distance(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}

    // 纯虚函数，用于计算距离
    virtual int calculate() const = 0;

    // 虚析构函数确保正确释放资源
    virtual ~Distance() {}
};

// 派生类ManhattanDistance，计算曼哈顿距离
class ManhattanDistance : public Distance {
public:
    ManhattanDistance(int a, int b, int c, int d) : Distance(a, b, c, d) {}

    // 实现曼哈顿距离计算：|x1-x2| + |y1-y2|
    int calculate() const override {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};

// 派生类EuclideanDistance，计算欧几里得距离平方
class EuclideanDistance : public Distance {
public:
    EuclideanDistance(int a, int b, int c, int d) : Distance(a, b, c, d) {}

    // 实现欧几里得距离平方计算：(x1-x2)^2 + (y1-y2)^2
    int calculate() const override {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return dx * dx + dy * dy;
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 创建派生类对象并用基类指针指向
    Distance* manhattan = new ManhattanDistance(x1, y1, x2, y2);
    Distance* euclidean = new EuclideanDistance(x1, y1, x2, y2);

    // 通过基类指针调用calculate()函数实现动态联编
    cout << manhattan->calculate() << " " << euclidean->calculate() << endl;

    // 释放内存
    delete manhattan;
    delete euclidean;

    return 0;
}