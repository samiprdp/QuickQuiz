#include <stdio.h>

int main()
{
    int number;
    printf("Enter the number:");

    if (scanf("%d", &number) != 1)
    {
        printf("Not allowed\n");
        return 1;
    }
    printf("%d",number);
}