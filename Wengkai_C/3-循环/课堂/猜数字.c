#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));
    int a=rand()%100+1;

    int count=0;
    printf("%d\n",a);

    return 0; 
}