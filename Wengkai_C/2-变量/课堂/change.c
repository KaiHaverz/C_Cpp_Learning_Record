#include<stdio.h>

const int AMOUNT=100;

int main()
{ 
    int price=0;
    printf("请输入金额:");
    scanf("%d",&price);

    int change=AMOUNT-price;
    printf("找零%d元\n",change);

    return 0;
}