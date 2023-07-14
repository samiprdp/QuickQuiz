#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./login.h"

#define MAX_ACCOUNTS 100

struct Account {
    char username[100];
    char password[100];
};

void login(struct Account[], int);
void fail_login();
int create(struct Account[], int);

int main()
{
    int choose;
    struct Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    printf("Welcome to Program\n");

    FILE* file = fopen("main.txt", "r"); // Open the file in read mode

    if (file != NULL)
    {
        while (fscanf(file, "username: %s password: %s\n", accounts[numAccounts].username, accounts[numAccounts].password) == 2)
        {
            numAccounts++;
        }

        fclose(file); // Close the file
    }
    else
    {
        printf("Error opening the file.\n");
        return -1; // Return an error code to indicate failure
    }

    printf("1. Create account\n2. Login\n3. Exit\n");
    scanf("%d", &choose);

    switch (choose)
    {
        case 1:
            create(accounts, numAccounts);
            numAccounts++;
            break;
        case 2:
            login(accounts, numAccounts);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid option. Exiting program.\n");
            break;
    }

    return 0;
}

int create(struct Account accounts[], int numAccounts)
{
    char name[100], pass[100];

    printf("Create a username: ");
    scanf("%s", name);

    printf("Create a password: ");
    scanf("%s", pass);

    FILE* file = fopen("main.txt", "a"); // Open the file in append mode

    if (file != NULL)
    {
        fprintf(file, "username: %s password: %s\n", name, pass); // Write the username and password to the file
        fclose(file); // Close the file

        strcpy(accounts[numAccounts].username, name);
        strcpy(accounts[numAccounts].password, pass);
    }
    else
    {
        printf("Error opening the file.\n");
        return -1; // Return an error code to indicate failure
    }

    return 0;
}

void login(struct Account accounts[], int numAccounts)
{
    char username[100], password[100];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < numAccounts; i++)
    {
        if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0)
        {
            system("clear");
            login_success();
            return;
        }
    }

    system("clear");
    fail_login();
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
