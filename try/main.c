#include <stdio.h>

int main() {
    int n, j,i;
    printf("Enter the number ");
    scanf("%d",&i);
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    // Display multiplication table

        for (j = 1; j <= n; j++) {
            printf("%d x %d = %d\n", i, j, i*j);
        }
        printf("\n");
    return 0;
}