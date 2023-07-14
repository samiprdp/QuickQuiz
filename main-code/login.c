#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "./login.h"

void starting_logic();

void login_success(char username[])
{
    struct termios term, old_term;
    tcgetattr(STDIN_FILENO, &term);
    old_term = term;
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    printf("Login successful!");
    fflush(stdout);
    sleep(2);
    printf("\rWelcome to Institution %s\n ", username);
    fflush(stdout);
    sleep(2);
    tcsetattr(STDIN_FILENO, TCSANOW, &old_term); // Restore original terminal settings    
    starting_logic();    
    tcsetattr(STDIN_FILENO, TCSANOW, &old_term); // Restore original terminal settings
}

void starting_logic()
{
    struct termios term, old_term;
    tcgetattr(STDIN_FILENO, &term);
    old_term = term;
    term.c_lflag &= ~(ICANON);
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    
    char try[100];
    printf("\nEnter: ");
    fflush(stdout);
    tcflush(STDIN_FILENO, TCIFLUSH); // Clear input buffer
    scanf("%s", try);
    printf("%s\n", try);
    fflush(stdout);
}
