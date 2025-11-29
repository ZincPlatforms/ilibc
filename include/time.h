#ifndef ILIBC_TIME_H
#define ILIBC_TIME_H

#include "syscall.h"

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

time_t time(time_t* tloc);
unsigned long get_milliseconds(void);
int sleep(unsigned int seconds);
int usleep(unsigned long usec);

#endif
