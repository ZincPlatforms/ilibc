#ifndef ILIBC_UNISTD_H
#define ILIBC_UNISTD_H

#include "syscall.h"

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

void exit(int status);
ssize_t write(int fd, const void* buf, size_t count);
ssize_t read(int fd, void* buf, size_t count);
pid_t getpid(void);
void yield(void);
int execv(const char* path, char* const argv[]);
int execve(const char* path, char* const argv[], char* const envp[]);
long syscall(long num, long arg1, long arg2, long arg3, long arg4, long arg5);

#endif
