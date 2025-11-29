#include "stdlib.h"
#include "string.h"

static char heap_space[1024 * 1024];
static size_t heap_offset = 0;

void exit(int status) {
    syscall1(SYS_EXIT, status);
    while(1);
}

void abort(void) {
    exit(EXIT_FAILURE);
}

void* malloc(size_t size) {
    if (size == 0) return NULL;
    
    size = (size + 15) & ~15UL;
    
    if (heap_offset + size > sizeof(heap_space)) {
        return NULL;
    }
    
    void* ptr = &heap_space[heap_offset];
    heap_offset += size;
    return ptr;
}

void* calloc(size_t nmemb, size_t size) {
    size_t total = nmemb * size;
    void* ptr = malloc(total);
    if (ptr) {
        memset(ptr, 0, total);
    }
    return ptr;
}

void* realloc(void* ptr, size_t size) {
    if (!ptr) return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    
    void* new_ptr = malloc(size);
    if (new_ptr && ptr) {
        memcpy(new_ptr, ptr, size);
    }
    return new_ptr;
}

void free(void* ptr) {
}

int atoi(const char* str) {
    return (int)atol(str);
}

long atol(const char* str) {
    long result = 0;
    int sign = 1;
    
    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }
    
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    return sign * result;
}

long long atoll(const char* str) {
    long long result = 0;
    int sign = 1;
    
    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }
    
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    return sign * result;
}

int abs(int n) {
    return n < 0 ? -n : n;
}

long labs(long n) {
    return n < 0 ? -n : n;
}

long long llabs(long long n) {
    return n < 0 ? -n : n;
}
