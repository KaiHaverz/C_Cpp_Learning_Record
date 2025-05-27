#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // 使用当前时间作为种子，让每次运行结果不同
    srand((unsigned int)time(NULL));
    // 生成 1 到 100 之间的随机整数
    int random_num = rand() % 100 + 1;

    int count=0;
    int guess=0;
    
    do{
        printf("请输入猜测的数字：");
        scanf("%d",&guess);
        count++;

        if(guess > random_num){
            printf("你猜的数字太大了！\n");
        }
        else if(guess < random_num){
            printf("你猜的数字太小了！\n");
        }
    }while(guess != random_num);

    printf("恭喜你，你只用了%d次，猜对了！正确数字是%d\n",count,random_num);

    return 0; 
}