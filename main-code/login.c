#include <stdio.h>
#include <unistd.h>

void login_success(char username[])
{
    printf("Login successful!");
    fflush(stdout);
    sleep(2);
    
    printf("\rWelcome to Institution %s\n", username);
    fflush(stdout);
    
    // Disable input for 2 seconds
    system("stty -icanon");
    sleep(2);
    system("stty icanon");
}
