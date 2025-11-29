#ifndef ILIBC_STRING_H
#define ILIBC_STRING_H

#include "syscall.h"

size_t strlen(const char* str);
char* strcpy(char* dest, const char* src);
int strcmp(const char* s1, const char* s2);
void* memset(void* s, int c, size_t n);
void* memcpy(void* dest, const void* src, size_t n);

#endif
