
#include "tester.h"

void print_red()
{
    printf("\033[1;31m");
}

void print_green()
{
    printf("\033[1;32m");
}

void print_black()
{
    printf("\033[1;30m");
}

void print_test_result(int i,char *success,char *fail)
{
    
    if (i)
    {
        print_green();
        printf("[OK]:");
        print_black();
        printf("%s\n",success);
        return;
    }
    print_red();
    printf("[KO]:");
    print_black();
    printf("%s",fail);
}