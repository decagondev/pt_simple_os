[bits 32]
global somefunction
[extern main] ; defines some calling point
call main ; this will call our function in kernel.c
jmp $ ; we should never get here

somefunction:
    pusha ; store the state of the cpu registers on the stack
    mov ebx, MESSAGE_ASM
    call print_pm
    popa ; restore all of the cpu register state
    ret

%include "boot/print_32bit.asm"

MESSAGE_ASM db 'This is from Assembly called in C Kernel', 0