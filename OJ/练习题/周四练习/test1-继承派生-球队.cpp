#include <iostream>
#include <cstring>
using namespace std;

// 抽象基类Team
class Team {
protected:
    char *name; // 球队名称
    int win;    // 胜场次
    int draw;   // 平场次
    int lose;   // 负场次

public:
    // 构造函数
    Team(const char* n, int w, int d, int l) : win(w), draw(d), lose(l) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    
    // 虚析构函数
    virtual ~Team() {
        delete[] name;
    }
    
    // 纯虚函数：计算积分
    virtual int score() const = 0;
    
    // 获取球队名称
    const char* getName() const {
        return name;
    }
};

// 国家队类
class National : public Team {
private:
    char *continent; // 所在大洲

public:
    // 构造函数
    National(const char* cont, const char* n, int w, int d, int l) 
        : Team(n, w, d, l) {
        continent = new char[strlen(cont) + 1];
        strcpy(continent, cont);
    }
    
    // 析构函数
    ~National() {
        delete[] continent;
    }
    
    // 计算积分
    int score() const override {
        return win * 3 + draw;
    }
    
    // 获取大洲
    const char* getContinent() const {
        return continent;
    }
};

// 俱乐部类
class Club : public Team {
private:
    char *country; // 所在国家

public:
    // 构造函数
    Club(const char* cntry, const char* n, int w, int d, int l) 
        : Team(n, w, d, l) {
        country = new char[strlen(cntry) + 1];
        strcpy(country, cntry);
    }
    
    // 析构函数
    ~Club() {
        delete[] country;
    }
    
    // 计算积分
    int score() const override {
        return win * 3 + draw;
    }
    
    // 获取国家
    const char* getCountry() const {
        return country;
    }
};

int main() {
    // 读取国家队信息
    char continent[100], nameA[100];
    int winA, drawA, loseA;
    cin >> continent >> nameA >> winA >> drawA >> loseA;
    
    // 读取俱乐部信息
    char country[100], nameB[100];
    int winB, drawB, loseB;
    cin >> country >> nameB >> winB >> drawB >> loseB;
    
    // 创建对象
    National national(continent, nameA, winA, drawA, loseA);
    Club club(country, nameB, winB, drawB, loseB);
    
    // 使用基类指针计算积分
    Team* teams[2] = {&national, &club};
    
    // 输出国家队信息
    cout << "TeamName: " << teams[0]->getName() << endl;
    cout << "Continent: " << national.getContinent() << endl;
    cout << "Score: " << teams[0]->score() << endl;
    
    // 输出俱乐部信息
    cout << "TeamName: " << teams[1]->getName() << endl;
    cout << "Country: " << club.getCountry() << endl;
    cout << "Score: " << teams[1]->score() << endl;
    
    return 0;
}