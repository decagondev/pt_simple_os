; to assemble we can do "nasm -f bin bootsector.asm -o bootsector.bin"
[org 0x7c00]
; constants
KERNEL_OFFSET equ 0x1000 ; TODO: use this value in the linking stage

mov [BOOT_DRIVE], dl; store bootdrive from dl
; setup a stack
mov bp, 0x9000
mov sp, bp

; entry point
mov bx, MESSAGE_BOOT
call println
call load_kernel
call pm_start
jmp $

; include files
%include "boot/printing.asm"
%include "boot/disk_tools.asm"
%include "boot/gdt.asm"
%include "boot/print_32bit.asm"
%include "boot/switch_pm.asm"


; load kernel function
[bits 16]
load_kernel:
    pusha
   
    mov bx, MESSAGE_KERNEL_LOAD
    call println

    mov bx, KERNEL_OFFSET ; read from disk and store in 0x1000
    mov dh, 3 ; this will grow bigger as our codebase does
    mov dl, [BOOT_DRIVE]
    call disk_load
    popa
    ret




[bits 32]
BEGIN_PM:
    mov ebx, MESSAGE_PM
    call print_pm
    call KERNEL_OFFSET
    jmp $

; data
BOOT_DRIVE db 0
MESSAGE_BOOT db 'Booting Lambda OS...', 0
MESSAGE_PM db 'Entered 32 Bit Protected Mode...', 0
MESSAGE_KERNEL_LOAD db 'Loading Kernel in to Memory', 0


times 510 - ($ - $$) db 0
dw 0xaa55