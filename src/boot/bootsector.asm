; to assemble we can do "nasm -f bin bootsector.asm -o bootsector.bin"
[org 0x7c00]
; entry point
mov bx, MESSAGE_BOOT
call println

jmp $

; include files
; printing to the screen
%include "boot/printing.asm"
%include "boot/disk_tools.asm"
%include "boot/gdt.asm"
; TODO: include a 32 Bit printing file here
%include "boot/switch_pm.asm"

; data
MESSAGE_BOOT db 'Booting Lambda OS...', 0

times 510 - ($ - $$) db 0
dw 0xaa55