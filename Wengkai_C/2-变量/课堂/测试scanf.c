#include <stdio.h>

int main()
{
    int a, b;
    a = 0;
    b = 0;

    //如果中间是逗号,那么输入的数字之间就要用逗号,不能用空格
    //出现在scanf里的东西都是有用的
    scanf("%d,%d", &a, &b);
    printf("a=%d b=%d\n", a, b);

    return 0;
}