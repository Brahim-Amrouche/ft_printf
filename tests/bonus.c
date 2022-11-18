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
    printf("\n String converter with flags \n");
    print_test_result(ft_printf("|%000006s|","hello") == 7,"String converter with 0 flag (it's undefined)");
    print_test_result(ft_printf("|%-----6s|","hello") == printf("|%-6s|","hello"),"String converter with - flag");
    print_test_result(ft_printf("|%-4s|","hello") == printf("|%-4s|","hello"),"String converter with - flag : Less than characters count");
    print_test_result(ft_printf("|%-s|","hello") == printf("|%-s|","hello"),"String converter with - flag : with no count");
    print_test_result(ft_printf("|%..10s|","hello") == 5,"String converter with . flag : multiple . flags");
    print_test_result(ft_printf("|%.10s|","hello") == printf("|%.10s|","hello"),"String converter with . flag");
    print_test_result(ft_printf("|%.3s|","hello") == printf("|%.3s|","hello"),"String converter with . flag : Less than characters count");
    print_test_result(ft_printf("|%.s|","hello") == printf("|%.s|","hello"),"String converter with . flag : with no count");
    print_test_result(ft_printf("|%####s|","hello") == 7,"String converter with # flag (it's undefined)");
    print_test_result(ft_printf("|%   s|","hello") == 7 , "String converter with 'space' flag (it's undefined)");
    print_test_result(ft_printf("|%+++s|","hello") == 7 , "String converter with + flag (it's undefined)");
    print_test_result(ft_printf("|%10s|","hello") == printf("|%10s|","hello") , "Optional -- String converter with 'left margin' flag");
    print_test_result(ft_printf("|%4s|","hello") == printf("|%4s|","hello") , "Optional -- String converter with 'left margin' flag : less than characters count");
    print_test_result(ft_printf("|%++##00  --10.4s|","hello") == printf("|%-10.4s|","hello") , "String converter with Mixed flags : 1");
    print_test_result(ft_printf("|%+#0 -2.4s|","hello") == printf("|%-2.4s|","hello") , "String converter with Mixed flags : 2");
    print_test_result(ft_printf("|%+#0 -2.s|","hello") == printf("|%-2.s|","hello") , "String converter with Mixed flags : 3");
    print_test_result(ft_printf("|%+#0 -2.s|","hello") == printf("|%-2.s|","hello") , "String converter with Mixed flags : 4");
    print_test_result(ft_printf("|%+#0 -.4s|","hello") == printf("|%-.4s|","hello") , "String converter with Mixed flags : 5");
    print_test_result(ft_printf("|%+#0 -.s|","hello") == printf("|%-.s|","hello") , "String converter with Mixed flags : 6");
    print_test_result(ft_printf("|%+#0 -.s|","") == printf("|%-.s|","") , "String converter with Mixed flags : 7");
    print_test_result(ft_printf("|%-11.0 +#s|","hello") == 5 , "String converter with invalid convertion syntax , just handle it the way you deem good");

    // pointer Converter
    char *p = "a pointer to hell";
    print_white();
    printf("\n Pointer converter with flags \n");
    print_test_result(ft_printf("|%000012p|",p) == 13 , "Pointer converter with 0 flag (it's undefined)");
    print_test_result(ft_printf("|%----15p|",p) == printf("|%-15p|",p) ,"Pointer converter with - flag");
    print_test_result(ft_printf("|%-15p|",p) == printf("|%-15p|",p) ,"Pointer converter with - flag");
    print_test_result(ft_printf("|%-10p|",p) == printf("|%-10p|",p) ,"Pointer converter with - flag : Less than characters count");
    print_test_result(ft_printf("|%-p|",p) == printf("|%-p|",p) ,"Pointer converter with - flag : no characters count");
    print_test_result(ft_printf("|%.1p|",p) == 13 ,"Pointer converter with . flag (it's undefined)");
    print_test_result(ft_printf("|%####p|",p) == 13 ,"Pointer converter with # flag (it's undefined)");
    print_test_result(ft_printf("|%   p|",p) == 13 ,"Pointer converter with 'space' flag (it's undefined)");
    print_test_result(ft_printf("|%++++p|",p) == 13 ,"Pointer converter with + flag (it's undefined)");
    print_test_result(ft_printf("|%15p|",p) == printf("|%15p|",p) ,"Optional -- Pointer converter with 'left margin' flag ");
    print_test_result(ft_printf("|%10p|",p) == printf("|%10p|",p) ,"Optional -- Pointer converter with 'left margin' flag : less than characters count");
    print_test_result(ft_printf("|%++++###0000   ---10.4p|",p) == printf("|%-10p|",p) , "Optional pointer converter with Mixed flags");
    print_test_result(ft_printf("|%-11.0 +#p|",p) == 5 , "String converter with invalid convertion syntax , just handle it the way you deem good");

    // Decimal Converter
    print_white();
    printf("\n Decimal converter with flags \n");
    print_test_result(ft_printf("|%00003d|",10) == printf("|%00003d|",10) , "Decimal converter with 0 flag");
    print_test_result(ft_printf("|%04d|",-10) == printf("|%04d|",-10) , "Decimal converter with 0 flag : with negative number");
    print_test_result(ft_printf("|%01d|",10) == printf("|%01d|",10) , "Decimal converter with 0 flag : with less than characters count");
    print_test_result(ft_printf("|%0d|",10) == printf("|%0d|",10) , "Decimal converter with 0 flag : with no count");
    print_test_result(ft_printf("|%0d|",0) == printf("|%0d|",0) , "Decimal converter with 0 flag : with no count and zero as parametre");
    print_test_result(ft_printf("|%---3d|",10)== printf("|%---3d|",10) , "Decimal converter with - flag");
    print_test_result(ft_printf("|%-3d|",-10)== printf("|%-3d|",-10) , "Decimal converter with - flag : with negative number");
    print_test_result(ft_printf("|%-1d|",10)== printf("|%-1d|",10) , "Decimal converter with - flag : with less than characters count");
    print_test_result(ft_printf("|%-d|",10) == printf("|%-d|",10) , "Decimal converter with - flag : with not count");
    print_test_result(ft_printf("|%-d|",0) == printf("|%-d|",0),"Decimal converter with - flag : with no count and zero as parameter");
    print_test_result(ft_printf("|%...3d|",10) == 5 ,"Decimal converter with . flag : multiple . flags");
    print_test_result(ft_printf("|%.3d|",10) == printf("|%.3d|",10) ,"Decimal converter with . flag ");
    print_test_result(ft_printf("|%.3d|",-10) == printf("|%.3d|",-10) ,"Decimal converter with . flag : with negative number");
    print_test_result(ft_printf("|%.1d|",10) == printf("|%.1d|",10), "Decimal converter with . flag : with less than characters count");
    print_test_result(ft_printf("|%.d|",10) == printf("|%.d|",10) ,"Decimal converter with . flag : with no count");
    print_test_result(ft_printf("|%.d|",0) == printf("|%.d|",0) ,"Decimal converter with . flag : with zero and no count");
    print_test_result(ft_printf("|%###d|",10) == 4,"Decimal converter with # flag (it's undefined)");
    print_test_result(ft_printf("|%   d|",10) == printf("|%   d|",10) , "Decimal converter with 'space' flag");
    print_test_result(ft_printf("|%   d|",-10) == printf("|%   d|",-10) , "Decimal converter with 'space' flag: with negative value");
    print_test_result(ft_printf("|%   d|",0) == printf("|%   d|",0) , "Decimal converter with 'space' flag: with zero value");
    print_test_result(ft_printf("|%+++d|",10) == printf("|%+++d|",10) , "Decimal converter with + flag");
    print_test_result(ft_printf("|%+++d|",-10) == printf("|%+++d|",-10) , "Decimal converter with + flag : with negative value");
    print_test_result(ft_printf("|%+++d|",0) == printf("|%+++d|",0), "Decimal converter with + flag : with zeor value");
    print_test_result(ft_printf("|%15d|",10) == printf("|%15d|",10) ,"Optional -- Decimal converter with 'left margin' flag ");
    print_test_result(ft_printf("|%4d|",-10) == printf("|%4d|",-10) ,"Optional -- Decimal converter with 'left margin' flag : with negative value");
    print_test_result(ft_printf("|%1d|",10) == printf("|%1d|",10) ,"Optional -- Decimal converter with 'left margin' flag : less than characters count");
    print_test_result(ft_printf("|% 04.3d|",10) == printf("|% 04.3d|",10) ,"Decimal converter mixed flags 1");
    print_test_result(ft_printf("|% -4.3d|",10) == printf("|% -4.3d|",10) ,"Decimal converter mixed flags 2");
    print_test_result(ft_printf("|% +04.3d|",10) == printf("|%+04.3d|",10) ,"Decimal converter mixed flags 3");
    print_test_result(ft_printf("|% +05.3d|",10) == printf("|%+05.3d|",10) ,"Decimal converter mixed flags 4");
    print_test_result(ft_printf("|% +-5.3d|",10) == printf("|%+-5.3d|",10) ,"Decimal converter mixed flags 5");
    print_test_result(ft_printf("|%+-5.3d|",-10) == printf("|%+-5.3d|",-10) ,"Decimal converter mixed flags 6");
    print_test_result(ft_printf("|% -5.3d|",-10) == printf("|% -5.3d|",-10) ,"Decimal converter mixed flags 7");
    print_test_result(ft_printf("|% -.d|",0) == printf("|% -.d|",0) ,"Decimal converter mixed flags 8");
    print_test_result(ft_printf("|%+-.d|",0) == printf("|%+-.d|",0) ,"Decimal converter mixed flags 9");
    print_test_result(ft_printf("|%+0.d|",0) == printf("|%+0.d|",0) ,"Decimal converter mixed flags 10");
    print_test_result(ft_printf("|%+-3.d|",0) == printf("|%+-3.d|",0) ,"Decimal converter mixed flags 11");
    print_test_result(ft_printf("|%+3.d|",0) == printf("|%+3.d|",0) ,"Decimal converter mixed flags 12");
    print_test_result(ft_printf("|%+++---   000###3.2d|",9) == printf("|%++++----3.2d|",9) ,"Decimal converter mixed flags 13");
    print_test_result(ft_printf("|%+1.d|",0) == printf("|%+1.d|",0), "Decimal converter mixed flags 14");

    // Integer Converter
    print_white();
    printf("\n Integer converter with flags \n");
    print_test_result(ft_printf("|%00003i|",10) == printf("|%00003i|",10) , "Integer converter with 0 flag");
    print_test_result(ft_printf("|%04i|",-10) == printf("|%04i|",-10) , "Integer converter with 0 flag : with negative number");
    print_test_result(ft_printf("|%01i|",10) == printf("|%01i|",10) , "Integer converter with 0 flag : with less than characters count");
    print_test_result(ft_printf("|%0i|",10) == printf("|%0i|",10) , "Integer converter with 0 flag : with no count");
    print_test_result(ft_printf("|%0i|",0) == printf("|%0i|",0) , "Integer converter with 0 flag : with no count and zero as parametre");
    print_test_result(ft_printf("|%---3i|",10)== printf("|%---3i|",10) , "Integer converter with - flag");
    print_test_result(ft_printf("|%-3i|",-10)== printf("|%-3i|",-10) , "Integer converter with - flag : with negative number");
    print_test_result(ft_printf("|%-1i|",10)== printf("|%-1i|",10) , "Integer converter with - flag : with less than characters count");
    print_test_result(ft_printf("|%-i|",10) == printf("|%-i|",10) , "Integer converter with - flag : with not count");
    print_test_result(ft_printf("|%-i|",0) == printf("|%-i|",0),"Integer converter with - flag : with no count and zero as parameter");
    print_test_result(ft_printf("|%...3i|",10) == 5 ,"Integer converter with . flag : multiple . flags");
    print_test_result(ft_printf("|%.3i|",10) == printf("|%.3i|",10) ,"Integer converter with . flag ");
    print_test_result(ft_printf("|%.3i|",-10) == printf("|%.3i|",-10) ,"Integer converter with . flag : with negative number");
    print_test_result(ft_printf("|%.1i|",10) == printf("|%.1i|",10), "Integer converter with . flag : with less than characters count");
    print_test_result(ft_printf("|%.i|",10) == printf("|%.i|",10) ,"Integer converter with . flag : with no count");
    print_test_result(ft_printf("|%.i|",0) == printf("|%.i|",0) ,"Integer converter with . flag : with zero and no count");
    print_test_result(ft_printf("|%###i|",10) == 4,"Integer converter with # flag (it's undefined)");
    print_test_result(ft_printf("|%   i|",10) == printf("|%   i|",10) , "Integer converter with 'space' flag");
    print_test_result(ft_printf("|%   i|",-10) == printf("|%   i|",-10) , "Integer converter with 'space' flag: with negative value");
    print_test_result(ft_printf("|%   i|",0) == printf("|%   i|",0) , "Integer converter with 'space' flag: with zero value");
    print_test_result(ft_printf("|%+++i|",10) == printf("|%+++i|",10) , "Integer converter with + flag");
    print_test_result(ft_printf("|%+++i|",-10) == printf("|%+++i|",-10) , "Integer converter with + flag : with negative value");
    print_test_result(ft_printf("|%+++i|",0) == printf("|%+++i|",0), "Integer converter with + flag : with zeor value");
    print_test_result(ft_printf("|%15i|",10) == printf("|%15i|",10) ,"Optional -- Integer converter with 'left margin' flag ");
    print_test_result(ft_printf("|%4i|",-10) == printf("|%4i|",-10) ,"Optional -- Integer converter with 'left margin' flag : with negative value");
    print_test_result(ft_printf("|%1i|",10) == printf("|%1i|",10) ,"Optional -- Integer converter with 'left margin' flag : less than characters count");
    print_test_result(ft_printf("|% 04.3i|",10) == printf("|% 04.3i|",10) ,"Integer converter mixed flags 1");
    print_test_result(ft_printf("|% -4.3i|",10) == printf("|% -4.3i|",10) ,"Integer converter mixed flags 2");
    print_test_result(ft_printf("|% +04.3i|",10) == printf("|%+04.3i|",10) ,"Integer converter mixed flags 3");
    print_test_result(ft_printf("|% +05.3i|",10) == printf("|%+05.3i|",10) ,"Integer converter mixed flags 4");
    print_test_result(ft_printf("|% +-5.3i|",10) == printf("|%+-5.3i|",10) ,"Integer converter mixed flags 5");
    print_test_result(ft_printf("|%+-5.3i|",-10) == printf("|%+-5.3i|",-10) ,"Integer converter mixed flags 6");
    print_test_result(ft_printf("|% -5.3i|",-10) == printf("|% -5.3i|",-10) ,"Integer converter mixed flags 7");
    print_test_result(ft_printf("|% -.i|",0) == printf("|% -.i|",0) ,"Integer converter mixed flags 8");
    print_test_result(ft_printf("|%+-.i|",0) == printf("|%+-.i|",0) ,"Integer converter mixed flags 9");
    print_test_result(ft_printf("|%+0.i|",0) == printf("|%+0.i|",0) ,"Integer converter mixed flags 10");
    print_test_result(ft_printf("|%+-3.i|",0) == printf("|%+-3.i|",0) ,"Integer converter mixed flags 11");
    print_test_result(ft_printf("|%+3.i|",0) == printf("|%+3.i|",0) ,"Integer converter mixed flags 12");
    print_test_result(ft_printf("|%+++---   000###3.2i|",9) == printf("|%++++----3.2i|",9) ,"Integer converter mixed flags 13");
    print_test_result(ft_printf("|%+1.i|",0) == printf("|%+1.i|",0), "Integer converter mixed flags 14");

    print_white();
    printf("\n Unsigned Intger converter with flags \n");
    print_test_result(ft_printf("|%00003u|",10) == printf("|%00003u|",10) , "Unsigned integer converter with 0 flag");
    print_test_result(ft_printf("|%015u|",-10) == printf("|%015u|",-10) , "Unsigned integer converter with 0 flag : with negative number");
    print_test_result(ft_printf("|%01u|",10) == printf("|%01u|",10) , "Unsigned integer converter with 0 flag : with less than characters count");
    print_test_result(ft_printf("|%0u|",10) == printf("|%0u|",10) , "Unsigned integer converter with 0 flag : with no count");
    print_test_result(ft_printf("|%0u|",0) == printf("|%0u|",0) , "Unsigned integer converter with 0 flag : with no count and zero as parametre");
    print_test_result(ft_printf("|%---3u|",10)== printf("|%---3u|",10) , "Unsigned integer converter with - flag");
    print_test_result(ft_printf("|%-3u|",-10)== printf("|%-3u|",-10) , "Unsigned integer converter with - flag : with negative number");
    print_test_result(ft_printf("|%-1u|",10)== printf("|%-1u|",10) , "Unsigned integer converter with - flag : with less than characters count");
    print_test_result(ft_printf("|%-u|",10) == printf("|%-u|",10) , "Unsigned integer converter with - flag : with not count");
    print_test_result(ft_printf("|%-u|",0) == printf("|%-u|",0),"Unsigned integer converter with - flag : with no count and zero as parameter");
    print_test_result(ft_printf("|%...3u|",10) == 5 ,"Unsigned integer converter with . flag : multiple . flags");
    print_test_result(ft_printf("|%.3u|",10) == printf("|%.3u|",10) ,"Unsigned integer converter with . flag ");
    print_test_result(ft_printf("|%.3u|",-10) == printf("|%.3u|",-10) ,"Unsigned integer converter with . flag : with negative number");
    print_test_result(ft_printf("|%.1u|",10) == printf("|%.1u|",10), "Unsigned integer converter with . flag : with less than characters count");
    print_test_result(ft_printf("|%.u|",10) == printf("|%.u|",10) ,"Unsigned integer converter with . flag : with no count");
    print_test_result(ft_printf("|%.u|",0) == printf("|%.u|",0) ,"Unsigned integer converter with . flag : with zero and no count");
    print_test_result(ft_printf("|%###u|",10) == 4,"Unsigned integer converter with # flag (it's undefined)");
    print_test_result(ft_printf("|%   u|",10) == 4 , "Unsigned integer converter with 'space' flag (it's undefined)");
    print_test_result(ft_printf("|%+++u|",10) == 4 , "Unsigned integer converter with + flag (it's undefined)");
    print_test_result(ft_printf("|%15u|",10) == printf("|%15u|",10) ,"Optional -- Unsigned integer converter with 'left margin' flag ");
    print_test_result(ft_printf("|%4u|",-10) == printf("|%4u|",-10) ,"Optional -- Integer converter with 'left margin' flag : with negative value");
    print_test_result(ft_printf("|%1u|",10) == printf("|%1u|",10) ,"Optional -- Unsigned integer converter with 'left margin' flag : less than characters count");
    print_test_result(ft_printf("|%04.3u|",10) == printf("|%04.3u|",10) ,"Unsigned integer converter mixed flags 1");
    print_test_result(ft_printf("|%-4.3u|",10) == printf("|%-4.3u|",10) ,"Unsigned integer converter mixed flags 2");
    print_test_result(ft_printf("|%04.3u|",10) == printf("|%04.3u|",10) ,"Unsigned integer converter mixed flags 3");
    print_test_result(ft_printf("|%05.3u|",10) == printf("|%05.3u|",10) ,"Unsigned integer converter mixed flags 4");
    print_test_result(ft_printf("|% +-5.3u|",10) == printf("|%-5.3u|",10) ,"Unsigned integer converter mixed flags 5");
    print_test_result(ft_printf("|%+-5.3u|",-10) == printf("|%-5.3u|",-10) ,"Unsigned integer converter mixed flags 6");
    print_test_result(ft_printf("|% -5.3u|",-10) == printf("|%-5.3u|",-10) ,"Unsigned integer converter mixed flags 7");
    print_test_result(ft_printf("|% -.u|",0) == printf("|%-.u|",0) ,"Unsigned integer converter mixed flags 8");
    print_test_result(ft_printf("|%+-.u|",0) == printf("|%-.u|",0) ,"Unsigned integer converter mixed flags 9");
    print_test_result(ft_printf("|%+0.u|",0) == printf("|%0.u|",0) ,"Unsigned integer converter mixed flags 10");
    print_test_result(ft_printf("|%+-3.u|",0) == printf("|%-3.u|",0) ,"Unsigned integer converter mixed flags 11");
    print_test_result(ft_printf("|%+3.u|",0) == printf("|%3.u|",0) ,"Unsigned integer converter mixed flags 12");
    print_test_result(ft_printf("|%+++---   000###3.2u|",9) == printf("|%----3.2u|",9) ,"Unsigned integer converter mixed flags 13");
    print_test_result(ft_printf("|%+1.u|",0) == printf("|%1.u|",0), "Unsigned integer converter mixed flags 14");


    print_white();
    printf("\n LowerCase Hexadecimal converter with flags \n");
    print_test_result(ft_printf("|%00003x|",10) == printf("|%00003x|",10),"Lower Case Hexadecimal with 0 flag" );
    print_test_result(ft_printf("|%09x|",-10) == printf("|%09x|",-10),"Lower Case Hexadecimal with 0 flag: negative number as parameter");
    print_test_result(ft_printf("|%09x|",0) == printf("|%09x|",0),"Lower Case Hexadecimal with 0 flag: zero as parameter");
    print_test_result(ft_printf("|%01x|",100) == printf("|%01x|",100),"Lower Case Hexadecimal with 0 flag : lesser than character count" );
    print_test_result(ft_printf("|%0x|",100) == printf("|%0x|",100),"Lower Case Hexadecimal with 0 flag : without count" );
    print_test_result(ft_printf("|%----9x|",10) == printf("|%-----9x|",10),"Lower Case Hexadecimal with - flag");
    print_test_result(ft_printf("|%-9x|",-10) == printf("|%-9x|",-10),"Lower Case Hexadecimal with - flag : with negative number as paramter");
    print_test_result(ft_printf("|%-9x|",0) == printf("|%-9x|",0),"Lower Case Hexadecimal with - flag : with negative number as paramter");
    print_test_result(ft_printf("|%-1x|",100) == printf("|%-1x|",100),"Lower Case Hexadecimal with - flag : lesser than character count");
    print_test_result(ft_printf("|%-x|",100) == printf("|%-x|",100),"Lower Case Hexadecimal with - flag : without count");
    print_test_result(ft_printf("|%..3x|",100) == 4,"Lower Case Hexadecimal with multiple . flags");
    print_test_result(ft_printf("|%.3x|",100) == printf("|%.3x|",100),"Lower Case Hexadecimal with . flag");
    print_test_result(ft_printf("|%.9x|",-100) == printf("|%.9x|",-100),"Lower Case Hexadecimal with . flag : negative value");
    print_test_result(ft_printf("|%.1x|",100) == printf("|%.1x|",100),"Lower Case Hexadecimal with . flag : lesser than characters count");
    print_test_result(ft_printf("|%.x|",100) == printf("|%.x|",100),"Lower Case Hexadecimal with . flag : with no count");
    print_test_result(ft_printf("|%.x|",0) == printf("|%.x|",0),"Lower Case Hexadecimal with . flag : with no count");
    print_test_result(ft_printf("|%###x|",10) == printf("|%###x|",10),"Unsigned integer converter with # flag");
    print_test_result(ft_printf("|%   x|",10) == 3,"Lower Case Hexadecimal converter with 'space' flag (it's undefined)");
    print_test_result(ft_printf("|%+++x|",10) == 3,"Lower Case Hexadecimal converter with + flag (it's undefined)");
    print_test_result(ft_printf("|%3x|",20) == printf("|%3x|",20) ,"Optional -- Lower Case Hexadecimal converter with 'left margin' flag ");
    print_test_result(ft_printf("|%9x|",-20) == printf("|%9x|",-20) ,"Optional -- Lower Case Hexadecimal converter with 'left margin' flag : with negative value");
    print_test_result(ft_printf("|%1x|",20) == printf("|%1x|",20) ,"Optional -- Lower Case Hexadecimal converter with 'left margin' flag : less than characters count");
    print_test_result(ft_printf("|%#3.5x|",5) == printf("|%#.5x|",5) , "Lower Case Hexadecimal converter mixed flags 1");

    print_white();
    printf("End Bonus ---------------------------------------------------\n");
}