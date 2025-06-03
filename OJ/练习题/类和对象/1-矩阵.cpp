#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;  // 长
    int width;   // 宽

public:
    // 构造函数
    Rectangle(int l, int w) : length(l), width(w) {}
    
    // 计算面积
    int getArea() {
        return length * width;
    }
    
    // 计算周长
    int getPerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    int l, w;
    cin >> l >> w;  // 读取长和宽
    
    // 创建矩形对象
    Rectangle rect(l, w);
    
    // 计算并输出面积和周长
    cout << rect.getArea() << endl;
    cout << rect.getPerimeter() << endl;
    
    return 0;
}