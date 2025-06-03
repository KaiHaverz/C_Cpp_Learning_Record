#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// 衬衣属性结构体
struct ShirtProperty
{
    double price;
    string origin;
    string material;

    // 重载<运算符，用于map键值比较
    bool operator<(const ShirtProperty &other) const
    {
        if (fabs(price - other.price) > 1e-9)
            return price < other.price;
        if (origin != other.origin)
            return origin < other.origin;
        return material < other.material;
    }
};

// 库存管理系统
class InventorySystem
{
private:
    map<ShirtProperty, int> inventory; // 库存映射表

public:
    // 入库操作
    void addShirts(int quantity, double price, const string &origin, const string &material)
    {
        if (quantity <= 0)
        {
            cout << "wrong" << endl;
            return;
        }

        ShirtProperty prop = {price, origin, material};
        inventory[prop] += quantity;
    }

    // 出库操作
    void removeShirts(int quantity, double price, const string &origin, const string &material)
    {
        if (quantity <= 0)
        {
            cout << "wrong" << endl;
            return;
        }

        ShirtProperty prop = {price, origin, material};
        auto it = inventory.find(prop);

        if (it == inventory.end())
        {
            cout << "wrong" << endl;
            return;
        }

        int currentStock = it->second;

        if (quantity > currentStock)
        {
            cout << "out " << currentStock << endl;
            inventory.erase(it);
        }
        else
        {
            it->second -= quantity;
            if (it->second == 0)
            {
                inventory.erase(it);
            }
            cout << "next" << endl;
        }
    }

    // 查询商品数量
    void getQuantity(double price, const string &origin, const string &material)
    {
        ShirtProperty prop = {price, origin, material};
        auto it = inventory.find(prop);
        cout << (it != inventory.end() ? it->second : 0) << endl;
    }

    // 计算总价值
    double calculateTotalValue()
    {
        double total = 0.0;
        for (const auto &item : inventory)
        {
            total += item.first.price * item.second;
        }
        return total;
    }
};

int main()
{
    InventorySystem system;
    string command;

    while (true)
    {
        cin >> command;

        if (command == "in")
        {
            int quantity;
            double price;
            string origin, material;

            cin >> quantity;
            cin >> price >> origin >> material;
            system.addShirts(quantity, price, origin, material);
        }
        else if (command == "out")
        {
            int quantity;
            double price;
            string origin, material;

            cin >> quantity;
            cin >> price >> origin >> material;
            system.removeShirts(quantity, price, origin, material);
        }
        else if (command == "num")
        {
            double price;
            string origin, material;

            cin >> price >> origin >> material;
            system.getQuantity(price, origin, material);
        }
        else if (command == "price")
        {
            double total = system.calculateTotalValue();
            cout << total << endl;
            break;
        }
    }

    return 0;
}