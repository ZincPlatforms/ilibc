#ifndef ILIBC_SYSCALL_H
#define ILIBC_SYSCALL_H

#define SYS_EXIT    0
#define SYS_WRITE   1
#define SYS_READ    2
#define SYS_OPEN    3
#define SYS_CLOSE   4
#define SYS_GETPID  5
#define SYS_FORK    6
#define SYS_EXEC    7
#define SYS_WAIT    8
#define SYS_KILL    9
#define SYS_MMAP    10
#define SYS_MUNMAP  11
#define SYS_YIELD   12
#define SYS_SLEEP   13
#define SYS_GETTIME 14
#define SYS_CLEAR   15
#define SYS_FB_INFO 16
#define SYS_FB_MAP  17
#define SYS_SIGNAL  18
#define SYS_SIGRETURN 19

typedef long ssize_t;
typedef unsigned long size_t;
typedef int pid_t;

long syscall0(long num);
long syscall1(long num, long arg1);
long syscall2(long num, long arg1, long arg2);
long syscall3(long num, long arg1, long arg2, long arg3);
long syscall4(long num, long arg1, long arg2, long arg3, long arg4);
long syscall5(long num, long arg1, long arg2, long arg3, long arg4, long arg5);

#endif
