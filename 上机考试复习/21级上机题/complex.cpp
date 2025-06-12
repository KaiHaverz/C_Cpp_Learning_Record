#include<iostream>
using namespace std;

class Complex{
private:
    int real;
    int img;

public:
    Complex(int r=0,int i=0):real(r),img(i) {}

    Complex operator+(const Complex& other){
        return Complex(real+other.real,img+other.img);
    }
    Complex operator-(const Complex& other){
        return Complex(real-other.real,img-other.img);
    }
    Complex operator*(const Complex& other){
        return Complex(real*other.real-img*other.img,real*other.img+img*other.real);
    }

    void show(){
        if(real==0){
            if(img==0) cout<<0<<endl;
            else if(img==1) cout<<"i"<<endl;
            else if(img==-1) cout<<"-i"<<endl;
            else cout<<img<<"i"<<endl;
        }
        else{
            cout<<real;
            if(img==0) cout<<""<<endl;
            else if(img==1) cout<<"+i"<<endl;
            else if(img==-1) cout<<"-i"<<endl;
            else if(img<0){
                cout<<"-"<< -img<<"i"<<endl;
            }
            else{
                cout<<"+"<<img<<"i"<<endl;
            }
        }
    }
};


int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    Complex c1(a,b);
    Complex c2(c,d);
    c1.show();
    c2.show();

    (c1+c2).show();
    (c1-c2).show();
    (c1*c2).show();

    return 0;
}