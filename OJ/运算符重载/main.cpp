#include <iostream>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

    // 辅助函数：简化分数
    void simplify()
    {
        if (denominator == 0)
            return; // 分母不为0，题目保证输入合法
        if (denominator < 0)
        { // 确保分母为正
            numerator *= -1;
            denominator *= -1;
        }
        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

    // 计算最大公约数
    static int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // 构造函数，默认值为0/1
    Rational(int num = 0, int den = 1) : numerator(num), denominator(den)
    {
        simplify();
    }

    // 成员函数重载加法
    Rational operator+(const Rational &other) const
    {
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    // 成员函数重载减法
    Rational operator-(const Rational &other) const
    {
        return Rational(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    // 前置自增运算符
    Rational &operator++()
    {
        numerator += denominator; // 分子加分母（相当于加1）
        return *this;
    }

    // 后置自增运算符
    Rational operator++(int)
    {
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    // 重载赋值运算符，取倒数并简化
    Rational &operator=(const Rational &other)
    {
        if (this != &other)
        {
            numerator = other.denominator;
            denominator = other.numerator;
            simplify();
        }
        return *this;
    }

    // 友元重载乘法
    friend Rational operator*(const Rational &a, const Rational &b)
    {
        return Rational(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    // 友元重载除法
    friend Rational operator/(const Rational &a, const Rational &b)
    {
        return Rational(a.numerator * b.denominator, a.denominator * b.numerator);
    }

    // 友元重载输出运算符
    friend ostream &operator<<(ostream &os, const Rational &r)
    {
        if (r.denominator == 1)
        {
            os << r.numerator;
        }
        else
        {
            os << r.numerator << '/' << r.denominator;
        }
        return os;
    }
};

int main()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    // 初始分数
    Rational r1(a1, a2), r2(b1, b2);

    // a) 加法
    Rational add = r1 + r2;
    cout << add << endl;

    // b) 减法
    Rational sub = r1 - r2;
    cout << sub << endl;

    // c) 乘法
    Rational mul = r1 * r2;
    cout << mul << endl;

    // d) 除法
    Rational div = r1 / r2;
    cout << div << endl;

    // e) 自增（使用副本避免修改原值）
    Rational r1_inc = r1;
    Rational r2_inc = r2;
    ++r1_inc;
    ++r2_inc;
    cout << r1_inc << " " << r2_inc << endl;

    // f) 颠倒赋值
    Rational reversed_r1, reversed_r2;
    reversed_r1 = r1; // 调用重载赋值运算符
    reversed_r2 = r2;
    cout << reversed_r1 << " " << reversed_r2 << endl;

    return 0;
}