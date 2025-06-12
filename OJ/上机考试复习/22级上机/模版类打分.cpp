#include<iostream>
using namespace std;

template <typename T>
class Grader
{
private:
    T* ScoreArr;
    int len;


public:
    Grader(T a[],int l):len(count){
        ScoreArr=new T[len];
        for(int i=0;i<len;i++){
            ScoreArr[i]=a[i];
        }
    }

    void sortAndShow(){
        
    }
};