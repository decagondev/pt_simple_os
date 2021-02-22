; TODO: logic for pm_print function
[bits 32]

; set some constants
VGA_MEMORY equ 0xb8000
DEFAULT_COLOR equ 0x0a


print_pm:
    pusha ; store the state of the cpu registers on the stack

    mov edx, VGA_MEMORY

    putchar_pm:
        mov al, [ebx]
        mov ah, DEFAULT_COLOR

        cmp al, 0
        je done_pm_string

        mov [edx], ax ; store char + attrib in VGA Mem
        add ebx, 1 ; next char
        add edx, 2 ; move to next vga position
        jmp putchar_pm

    done_pm_string:
    popa ; restore all of the cpu register state
    ret