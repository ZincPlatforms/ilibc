#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include <stddef.h>
#include <stdarg.h>

int putchar(int c) {
    char ch = c;
    return write(STDOUT_FILENO, &ch, 1) == 1 ? c : -1;
}

int puts(const char* s) {
    size_t len = strlen(s);
    if (write(STDOUT_FILENO, s, len) != (ssize_t)len) return -1;
    if (putchar('\n') == -1) return -1;
    return 0;
}

static void print_num(long num, int base) {
    char buf[32];
    int i = 0;
    int neg = 0;
    unsigned long unum;
    
    if (num == 0) {
        putchar('0');
        return;
    }
    
    if (num < 0 && base == 10) {
        neg = 1;
        unum = -num;
    } else {
        unum = (unsigned long)num;
    }
    
    while (unum > 0) {
        int digit = unum % base;
        buf[i++] = digit < 10 ? '0' + digit : 'a' + digit - 10;
        unum /= base;
    }
    
    if (neg) putchar('-');
    
    while (i > 0) {
        putchar(buf[--i]);
    }
}

int printf(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            
            // Handle length modifiers
            int is_long = 0;
            if (*fmt == 'l') {
                is_long = 1;
                fmt++;
            }
            
            switch (*fmt) {

                case 'd':
                case 'i': {
                    long v = va_arg(ap, long);
                    print_num(v, 10);
                    break;
                }

                case 'u': {
                    unsigned long v = va_arg(ap, unsigned long);
                    print_num(v, 10);
                    break;
                }

                case 'x': {
                    unsigned long v = va_arg(ap, unsigned long);
                    print_num(v, 16);
                    break;
                }

                case 's': {
                    const char* s = va_arg(ap, const char*);
                    while (*s) putchar(*s++);
                    break;
                }

                case 'c': {
                    int c = va_arg(ap, int);
                    putchar(c);
                    break;
                }

                case '%':
                    putchar('%');
                    break;

                default:
                    putchar('%');
                    if (is_long) putchar('l');
                    putchar(*fmt);
                    break;
            }
        } else {
            putchar(*fmt);
        }
        fmt++;
    }

    va_end(ap);
    return 0;
}

