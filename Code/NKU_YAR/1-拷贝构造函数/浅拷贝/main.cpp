#include"Cperson.h"
#include<iostream>

void main(void){
    Cperson Tom(10);
    Tom.Print();

    Cperson Jim(Tom);
    Jim.print();
}