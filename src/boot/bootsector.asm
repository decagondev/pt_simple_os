; to assemble we can do "nasm -f bin bootsector.asm -o bootsector.bin"
[org 0x7c00]
; entry point
mov bx, MESSAGE_BOOT
call println

jmp $

; include files
; printing to the screen
%include "boot/printing.asm"

; data
MESSAGE_BOOT db 'Booting Lambda OS...', 0

times 510 - ($ - $$) db 0
dw 0xaa55