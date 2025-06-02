#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 抽象基类：优惠策略
class CashSuper {
public:
    virtual double AcceptCash(double money) = 0;
    virtual ~CashSuper() {}
};

// 折扣策略
class CashRebate : public CashSuper {
private:
    double discountRate;
public:
    CashRebate(int q) : discountRate(q / 10.0) {}
    
    double AcceptCash(double money) override {
        return money * discountRate;
    }
};

// 满减策略
class CashReturn : public CashSuper {
private:
    double fullAmount;
    double reductionAmount;
public:
    CashReturn(double a, double b) : fullAmount(a), reductionAmount(b) {}
    
    double AcceptCash(double money) override {
        if (money >= fullAmount) {
            money -= reductionAmount;
        }
        return (money > 0) ? money : 0;
    }
};

// 先折扣后满减策略
class CashDiscountThenReturn : public CashSuper {
private:
    double discountRate;
    double fullAmount;
    double reductionAmount;
public:
    CashDiscountThenReturn(int q, double a, double b) : 
        discountRate(q / 10.0), fullAmount(a), reductionAmount(b) {}
    
    double AcceptCash(double money) override {
        money = money * discountRate;
        if (money >= fullAmount) {
            money -= reductionAmount;
        }
        return (money > 0) ? money : 0;
    }
};

int main() {
    int N;
    double M;
    cin >> N >> M;
    
    vector<CashSuper*> strategies;
    
    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;
        
        if (m == 1) {
            int q;
            cin >> q;
            strategies.push_back(new CashRebate(q));
        } 
        else if (m == 2) {
            int a, b;
            cin >> a >> b;
            strategies.push_back(new CashReturn(a, b));
        } 
        else if (m == 3) {
            int q, a, b;
            cin >> q >> a >> b;
            strategies.push_back(new CashDiscountThenReturn(q, a, b));
        }
    }
    
    for (CashSuper* strategy : strategies) {
        double result = strategy->AcceptCash(M);
        // 四舍五入取整输出
        cout << static_cast<int>(round(result)) << endl;
    }
    
    // 释放内存
    for (CashSuper* strategy : strategies) {
        delete strategy;
    }
    
    return 0;
}