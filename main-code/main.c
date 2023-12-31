#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
void logic(char[], char[]);
int program();
void fail_login();
int main()
{
    char name[100], pass[100];
    printf("Create a user-name: ");
    scanf("%s", name);
    printf("create a password: ");
    scanf("%s", pass);
    logic(pass, name);
    return 0;
}
void logic(char pass[], char name[])
{
    char username[100], password[100];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    if (strcmp(name, username) == 0 && strcmp(pass, password) == 0)
    {
        system("clear");
        program();
    }
    else
    {
        system("clear");
        fail_login();
    }
}
int program()
{
    login();
    return 0;
}
void fail_login()
{
    int choose;
    printf("Choose an option below:\n");
    printf("Press 1 to retry\n");
    printf("Press 2 to exit program\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        main();
        break;
    case 2:
        exit(0);
        break;
    default:
        printf("Invalid option. Exiting program.\n");
        break;
    }
}
