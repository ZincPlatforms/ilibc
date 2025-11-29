#include "signal.h"

sighandler_t signal(int sig, sighandler_t handler) {
    return (sighandler_t)syscall2(SYS_SIGNAL, sig, (long)handler);
}

int raise(int sig) {
    return (int)syscall2(SYS_KILL, syscall0(SYS_GETPID), sig);
}
