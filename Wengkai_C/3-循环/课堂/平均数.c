#include <stdio.h>

int main()
{
    int num;
    int count = 0;
    float sum = 0;

    scanf("%d", &num);
    while (num != -1)
    {
        count++;
        sum += num;
        scanf("%d", &num);
    }

    printf("%.2f\n", float(sum/count));

    return 0;
}