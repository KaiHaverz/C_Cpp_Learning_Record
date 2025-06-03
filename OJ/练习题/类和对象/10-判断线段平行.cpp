#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// 点类
class Point
{
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// 线段类
class MyLine
{
private:
    Point e1, e2; // 两个端点
public:
    // 构造函数
    MyLine(Point p1, Point p2) : e1(p1), e2(p2) {}

    // 求线段长度
    double length()
    {
        int dx = e1.x - e2.x;
        int dy = e1.y - e2.y;
        return sqrt(dx * dx + dy * dy);
    }

    // 判断是否与坐标轴相交
    bool intersectAxis()
    {
        // 与x轴相交（端点y坐标异号或至少一端点在x轴上）
        if ((e1.y == 0) || (e2.y == 0) || (e1.y * e2.y < 0))
            return true;

        // 与y轴相交（端点x坐标异号或至少一端点在y轴上）
        if ((e1.x == 0) || (e2.x == 0) || (e1.x * e2.x < 0))
            return true;

        return false;
    }

    // 计算方向向量（用于判断平行）
    pair<int, int> directionVector()
    {
        return {e2.x - e1.x, e2.y - e1.y};
    }

    // 友元函数：判断两条线段是否平行
    friend bool areParallel(MyLine &l1, MyLine &l2);
};

// 判断两条线段是否平行
bool areParallel(MyLine &l1, MyLine &l2)
{
    auto v1 = l1.directionVector();
    auto v2 = l2.directionVector();

    // 叉积为零表示平行
    return (v1.first * v2.second == v1.second * v2.first);
}

int main()
{
    // 读取第一组点
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    MyLine line1(p1, p2);

    // 读取第二组点
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    Point p3(x3, y3), p4(x4, y4);
    MyLine line2(p3, p4);

    // 输出第一行
    cout << fixed << setprecision(2) << line1.length() << " "
         << line1.intersectAxis() << endl;

    // 输出第二行
    cout << fixed << setprecision(2) << line2.length() << " "
         << line2.intersectAxis() << endl;

    // 输出第三行
    cout << areParallel(line1, line2) << endl;

    return 0;
}