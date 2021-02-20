; to assemble we can do "nasm -f bin bootsector.asm -o bootsector.bin"
[org 0x7c00]
; entry point

jmp $

; data


times 510 - ($ - $$) db 0
dw 0xaa55