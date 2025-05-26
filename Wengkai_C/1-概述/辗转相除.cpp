#include<iostream>
using namespace std;

//辗转相除,求最大公约数
int func(int u,int v){
    while(v!=0){
        int temp=u%v;
        u=v;
        v=temp;
    }

    return u;   //返回最大公约数
}

//求最小公倍数
int func1(int u,int v){
    int temp=func(u,v);

    return u*v/temp;
}
int main(){
    int u,v;
    cin>>u>>v;

    cout<<"最大公约数:"<<func(u,v)<<endl<<"最小公倍数:"<<func1(u,v)<<endl;
    return 0;

}