#ifndef ILIBC_SIGNAL_H
#define ILIBC_SIGNAL_H

#include "syscall.h"

#define NSIG 32

#define SIGKILL 9
#define SIGSEGV 11
#define SIGTERM 15
#define SIGUSR1 10
#define SIGUSR2 12

typedef void (*sighandler_t)(int);

#define SIG_DFL ((sighandler_t)0)
#define SIG_IGN ((sighandler_t)1)

sighandler_t signal(int sig, sighandler_t handler);
int raise(int sig);

#endif
