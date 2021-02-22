[bits 32]
[extern main] ; defines some calling point
call main ; this will call our function in kernel.c
jmp $ ; we should never get here