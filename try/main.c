#include <stdio.h>

int main()
{
    int number, answer;
    printf("Enter the number:");

    if (scanf("%d", &number) != 1)
    {
        printf("Not allowed\n");
        return 0;
    }

    answer = number & 1;

    if (answer == 0)
    {
        printf("Even\n");
    }
    else if (answer == 1)
    {
        printf("Odd\n");
    }
    else
    {
        printf("Not allowed\n");
    }
    
    return 0;
}
