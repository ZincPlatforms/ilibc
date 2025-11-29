#ifndef ILIBC_STDIO_H
#define ILIBC_STDIO_H

#include "syscall.h"

int putchar(int c);
int puts(const char* s);
int printf(const char* fmt, ...);

#endif
