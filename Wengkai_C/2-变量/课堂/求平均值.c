#include<stdio.h>

int main()
{ 
    int a,b;
    printf("请输入两个数字：");
    scanf("%d%d",&a,&b);
    printf("平均数是:%.2f\n",(float)(a+b)/2);

    return 0;
}
