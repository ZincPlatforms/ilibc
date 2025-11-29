#include "unistd.h"

void exit(int status) {
    syscall1(SYS_EXIT, status);

    while(1) {
        __asm__ volatile("pause");
    }
}

ssize_t write(int fd, const void* buf, size_t count) {
    return syscall3(SYS_WRITE, fd, (long)buf, count);
}

ssize_t read(int fd, void* buf, size_t count) {
    return syscall3(SYS_READ, fd, (long)buf, count);
}

pid_t getpid(void) {
    return syscall0(SYS_GETPID);
}

void yield(void) {
    syscall0(SYS_YIELD);
}

int execv(const char* path, char* const argv[]) {
    return syscall3(SYS_EXEC, (long)path, (long)argv, 0);
}

int execve(const char* path, char* const argv[], char* const envp[]) {
    return syscall3(SYS_EXEC, (long)path, (long)argv, (long)envp);
}

long syscall(long num, long arg1, long arg2, long arg3, long arg4, long arg5) {
    return syscall5(num, arg1, arg2, arg3, arg4, arg5);
}
