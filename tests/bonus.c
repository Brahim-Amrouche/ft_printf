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
    print_test_result(ft_printf("|%.1c|",'a') == 3 , "Char converter with precision flag (it's undefined)");
    print_test_result(ft_printf("|%#c|",'a')  == 3,"Char converter with # flag (it's undefined)");
    print_test_result(ft_printf("|% c|",'a') == 3,"Char converter with 'space' flag (it's undefined)");
    print_test_result(ft_printf("|%+c|",'a') == 3,"Char converter with + flag (it's undefined)");
    print_test_result(ft_printf("|%2c|",'a') == printf("|%2c|",'a'),"Char converter with 'left marging' flag");

    print_white();
    printf("End Bonus ---------------------------------------------------\n");
}