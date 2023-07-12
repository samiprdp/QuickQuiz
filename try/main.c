#include <stdio.h>

int main()
{
    int a[100], n, i, j, max, min;

    printf("Enter the value of n (max 100):\n");
    scanf("%d", &n);

    printf("Start entering numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    min = a[0];
    max = a[0];
    for(i = 0; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    printf("%d is min\n", min);
    printf("%d is max\n", max);

    return 0;
}