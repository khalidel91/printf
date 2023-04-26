#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
int case_cs(int i, va_list arg, int *count);
char *int_to_base(int num, int base);
int case_di(int i, va_list arg, int *count);
int casebin(int i, va_list arg, int *count);


#endif /*MAIN_H*/
