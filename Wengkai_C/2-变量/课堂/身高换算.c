#include<stdio.h>  

float func1(int foot,int inch){
    return (foot+inch/12.0)*0.3048;
}



int main()
{
    printf("请输入身高英尺和英寸,比如5尺7寸,输入5 7:：");
    int foot,inch;
    scanf("%d %d",&foot,&inch);

    //取浮点数,两位小数
    //需要除以12.0,两个整数相除,返回的是整数,所以要用12.0
    printf("身高是%.2f米.\n",(foot+inch/12.0)*0.3048);

    
    return 0;
}