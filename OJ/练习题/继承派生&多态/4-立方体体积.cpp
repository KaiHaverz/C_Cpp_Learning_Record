#include <iostream>
#include <cmath>
using namespace std;

// 抽象基类：圆
class Circle {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}
    virtual ~Circle() {}
    
    // 纯虚函数 - 用于多态
    virtual double area() const = 0;
    virtual int volume() const = 0; // 返回整数体积（以π为单位）
};

// 派生类：圆柱
class Cylinder : public Circle {
private:
    double height;
public:
    Cylinder(double r, double h) : Circle(r), height(h) {}
    
    double area() const override {
        // 表面积 = 2πr(h + r)
        return 2 * radius * (height + radius);
    }
    
    int volume() const override {
        // 体积 = πr²h
        return static_cast<int>(radius * radius * height);
    }
};

// 派生类：圆锥
class Cone : public Circle {
private:
    double height;
public:
    Cone(double r, double h) : Circle(r), height(h) {}
    
    double area() const override {
        // 斜高
        double slant = sqrt(radius * radius + height * height);
        // 表面积 = πr(r + slant)
        return radius * (radius + slant);
    }
    
    int volume() const override {
        // 体积 = (1/3)πr²h
        return static_cast<int>(radius * radius * height / 3);
    }
};

// 派生类：球
class Sphere : public Circle {
public:
    Sphere(double r) : Circle(r) {}
    
    double area() const override {
        // 表面积 = 4πr²
        return 4 * radius * radius;
    }
    
    int volume() const override {
        // 体积 = (4/3)πr³
        return static_cast<int>(4.0 / 3.0 * radius * radius * radius);
    }
};

int main() {
    int n;
    cin >> n;
    
    // 基类指针数组
    Circle** shapes = new Circle*[n];
    
    // 处理每个输入
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // 圆柱
            double r, h;
            cin >> r >> h;
            shapes[i] = new Cylinder(r, h);
        }
        else if (type == 2) {
            // 圆锥
            double r, h;
            cin >> r >> h;
            shapes[i] = new Cone(r, h);
        }
        else if (type == 3) {
            // 球
            double r;
            cin >> r;
            shapes[i] = new Sphere(r);
        }
        else {
            // 无效类型
            shapes[i] = nullptr;
            // 跳过无效参数
            double dummy;
            while (cin.get() != '\n' && cin.peek() != EOF) {
                cin >> dummy;
            }
        }
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        if (shapes[i]) {
            cout << shapes[i]->volume() << endl;
            delete shapes[i];
        }
    }
    
    delete[] shapes;
    return 0;
}