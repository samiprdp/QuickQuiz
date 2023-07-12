#include <stdio.h>

int main() {
    int n,i,a=0,b=1,c;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    // Display multiplication table
    printf("%d\n%d\n",a,b);
        for (i = 1; i <= n; i++) {
            printf("%d\n",c);
            c=a+b;
            a=b;
            b=c;
        }
    return 0;
}