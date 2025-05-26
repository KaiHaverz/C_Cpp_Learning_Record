#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int hour1,min1,hour2,min2;
    scanf("%d:%d %d:%d",&hour1,&min1,&hour2,&min2);

    int t1=hour1*60+min1;
    int t2=hour2*60+min2;

    int t=abs(t2-t1);

    printf("时间差: %d小时%d分钟\n",t/60,t%60);

    return 0;
}