#include<stdio.h>

int main()
{
    int time,during_time;
    scanf("%d %d",&time,&during_time);

    time=(time/100)*60+time%100;
    time+=during_time;

    printf("%d\n",time/60*100+time%60);

    return 0;
}