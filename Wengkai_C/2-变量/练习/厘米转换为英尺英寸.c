#include<stdio.h>

int main()
{
    int cm;
    printf("请输入厘米数：");
    scanf("%d",&cm);

    int inch,foot;
    inch = cm / 2.54;
    foot = inch / 12;
    inch = inch % 12;

    printf("%d厘米等于%d英尺%d英寸\n",cm,foot,inch);

    return 0;
}