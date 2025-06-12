#include<iostream>
using namespace std;

class Vehicle{
protected:
    string brand,model;

public:
    Vehicle(string b,string m):brand(b),model(m) {}
    virtual double calculate(int days)=0;
    virtual void display()=0;
    ~Vehicle(){}
};

class Car : public Vehicle{
protected:
    int seat;
public:
    Car(string b,string m,int s):Vehicle(b,m),seat(s) {}
    double calculate(int days) override{
        return (300+10*seat)*days;
    }
    void display() override{
        cout<<"Car "<<brand<<" "<<model<<" ";
    }
};

class Motor : public Vehicle{
protected:
    int cc;
public:
    Motor(string b,string m,int c):Vehicle(b,m),cc(c) {}
    double calculate(int days) override{
        return 150*cc*days;
    }
    void display() override{
        cout<<"Motor "<<brand<<" "<<model<<" ";
    }
};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        string brand,model;
        int a,b;
        cin>>c>>brand>>model>>a>>b;

        if(c=='C'){
            Car* c1=new Car(brand,model,a);
            double fee=c1->calculate(b);
            c1->display();
            cout<<fee<<endl;
        }
        else if(c=='M'){
            Motor* m1=new Motor(brand,model,a);
            double fee=m1->calculate(b);
            m1->display();
            cout<<fee<<endl;
        }
    }

    return 0;
}