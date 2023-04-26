#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int case_cs(int i, va_list arg, int *num_prt_char);
char *int_to_base(int num, int base);
int case_di(int i, va_list arg, int *num_prt_char);
int handle_binary(int i, va_list arg, int *num_prt_char);


#endif /*MAIN_H*/
