#include "time.h"

unsigned long get_milliseconds(void) {
    return (unsigned long)syscall0(SYS_GETTIME);
}

time_t time(time_t* tloc) {
    time_t seconds = (time_t)(get_milliseconds() / 1000);
    if (tloc) {
        *tloc = seconds;
    }
    return seconds;
}

int sleep(unsigned int seconds) {
    return (int)syscall1(SYS_SLEEP, seconds * 1000);
}

int usleep(unsigned long usec) {
    return (int)syscall1(SYS_SLEEP, usec / 1000);
}
