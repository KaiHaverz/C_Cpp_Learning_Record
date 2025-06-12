#include<iostream>
#include<cstring>
using namespace std;

class Student{
protected:
    string name;
    int age;
    string home;

public:
    Student(string n,int a,string h):name(n),age(a),home(h) {}

    virtual void UpdateStu(string n,int a,string h,int at,int s)=0;
    virtual void show()=0;
};

class C_Stu : public Student{
protected:
    int attribute;
public:
    C_Stu(string n,int a,string h,int at): Student(n,a,h),attribute(at) {}

    void UpdateStu(string n,int a,string h,int at,int s) override{
        home=h;
        attribute=at;
    }



    void show() override{
        string kind;
        switch (attribute)
        {
            case(0): kind="undergraduate"; break;
            case(1): kind="master"; break;
            case(2): kind="doctor"; break;
            case(3): kind="other"; break;
            default:kind="UNKNOWN";
        }

        cout<<name<<" "<<age<<" "<<kind<<" "<<home<<endl;
    }
};

class H_Stu : public Student{
protected:
    int score;
public:
    H_Stu(string n,int a,string h,int s): Student(n,a,h),score(s) {}

    void UpdateStu(string n,int a,string h,int at,int s) override{
        home=h;
        score=s;
    }

    void show() override{
        cout<<name<<" "<<age<<" "<<score<<" "<<home<<endl;
    }
};

int main(){
    //大学生
    string name;
    int age;
    int att;
    string home;
    cin>>name>>age>>att>>home;

    string newHome;
    int newAtt;
    cin>>newHome>>newAtt;

    //高中生
    string name1;
    int age1;
    int score;
    string home1;
    cin>>name1>>age1>>score>>home1;

    string newHome1;
    int newScore;
    cin>>newHome1>>newScore;


    Student *c=new C_Stu(name,age,home,att);
    c->show();
    c->UpdateStu("0",0,newHome,newAtt,0);
    c->show();

    Student *h=new H_Stu(name1,age1,home1,score);
    h->show();
    h->UpdateStu("0",0,newHome1,0,newScore);
    h->show();

    return 0;
}