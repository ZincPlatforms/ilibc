bits 64

extern main
extern exit

section .text._start
global _start

_start:
    xor rbp, rbp
    
    pop rdi
    mov rsi, rsp
    
    call main
    
    mov rdi, rax
    call exit
    
    hlt

section .note.GNU-stack noalloc noexec nowrite progbits
