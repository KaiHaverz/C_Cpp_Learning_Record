#include<stdio.h>

void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{ 
    int a,b;
    scanf("%d %d",&a,&b);
    printf("a=%d b=%d\n",a,b);

    //swap(a,b);

    printf("a=%d b=%d\n",a,b);

    return 0;
}