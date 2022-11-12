#ifndef TESTER_H
# define TESTER_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

void	print_white(void);
void	print_black(void);
void	print_test_result(int i, char *test_message);

#endif