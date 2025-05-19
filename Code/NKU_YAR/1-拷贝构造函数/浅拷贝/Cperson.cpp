#include"Cperson.h"
#include<iostream>

using namespace std;

Cperson::Cperson(int age):m_age(age)
{
	
}

void Cperson::Print(void){
    cout<<"My age is "<<m_age<<endl;
}