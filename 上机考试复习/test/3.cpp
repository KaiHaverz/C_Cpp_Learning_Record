#include<iostream>
using namespace std;

template<class T>
class MyContainer{
private:
    T* data;
    int len;
    int capacity;

public:
    MyContainer(T arr[],int l){
        len=l;
        capacity=len*10;
        data=new T[capacity];

        for(int i=0;i<len;i++){
            data[i]=arr[i];
        }
    }


    void add(const T& n){
        data[len]=n;
        len++;
    }

    bool remove(int idx){
        if(len==0){
            cout<<"None"<<endl;
            return false;
        }
        
        if(idx<0 || idx>len){
            cout<<"Bounds Limit"<<endl;
            return false;
        }
        else{
            for(int i=idx;i<len;i++){
                data[i]=data[i+1];
            }
            len--;
            return true;
        }
    }

    bool empty(){
        if(len==0) return true;
        else return false;
    }

    int size(){
        return len;
    }

    void display(){
        cout<<"[";
        for(int i=0;i<len-1;i++){
            cout<<data[i]<<",";
        }
        cout<<data[len-1]<<"]"<<endl;
    }

    void clear(){
        len=0;
    }
};


int main(){
    
}