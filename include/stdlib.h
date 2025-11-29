#ifndef ILIBC_STDLIB_H
#define ILIBC_STDLIB_H

#include "syscall.h"

#define NULL ((void*)0)

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void exit(int status);
void abort(void);

void* malloc(size_t size);
void* calloc(size_t nmemb, size_t size);
void* realloc(void* ptr, size_t size);
void free(void* ptr);

int atoi(const char* str);
long atol(const char* str);
long long atoll(const char* str);

int abs(int n);
long labs(long n);
long long llabs(long long n);

#endif
