#include "tester.h"
#include "ft_printf.h"

void bonus ()
{
    print_white();
    printf("Bonus ------------------------------------------------------\n");
    printf("Some of these are personal tests so take them with a grain of salt \n");
    printf("you can deal with the undefined behaviors as you please \n");
    printf("there is an extra converter included i'll call it the left margin and it has this structure %%number[converter] \n");
    
    // Char Converter
    printf("Char converter with flags \n");
    print_test_result(ft_printf("|%02c|",'a') == 3,"Char converter with 0 flag (it's undefined)");
    print_test_result(ft_printf("|%-2c|",'a') == printf("|%-2c|",'a'),"Char converter with - flag");
    print_test_result(ft_printf("|%-1c|",'a') == printf("|%-1c|",'a'),"Char converter with - flag (less than the printable char count)");
    print_test_result(ft_printf("|%.1c|",'a') == 3 , "Char converter with precision flag (it's undefined)");
    print_test_result(ft_printf("|%#c|",'a')  == 3,"Char converter with # flag (it's undefined)");
    print_test_result(ft_printf("|% c|",'a') == 3,"Char converter with 'space' flag (it's undefined)");
    print_test_result(ft_printf("|%+c|",'a') == 3,"Char converter with + flag (it's undefined)");
    print_test_result(ft_printf("|%2c|",'a') == printf("|%2c|",'a'),"Optional -- Char converter with 'left marging' flag");
    print_test_result(ft_printf("|%1c|",'a') == printf("|%1c|",'a'),"Optional -- Char converter with 'left marging' flag (less than the printable char count)");
    print_test_result(ft_printf("|%0-# +2.c|",'a') == 4,"Char converter check mixin all flags together");
    print_test_result(ft_printf("|%10-x|",'a')== 3 , "Char Converter with invalid syntax , just handle it the way you deem good");

    // String Converter
    print_white();
    printf("String converter with flags \n");
    print_test_result(ft_printf("|%06s|","hello") == 7,"String converter with 0 flag (it's undefind)");
    print_test_result(ft_printf("|%-6s|","hello") == 8, "String converter with - flag");

    print_white();
    printf("End Bonus ---------------------------------------------------\n");
}