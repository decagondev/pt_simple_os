; switch to protected mode

; 1. stop any interrupts
; cli to clear interrupt
cli ; dissable interrupts

; 2. load gdt using lgdt passing in the gdt_descriptor
lgdt [gdt_descriptor]

; 3. set the 32bit flag inside the control register cr0
mov eax, cr0 ; copy the data in to eax
or eax, 0x1 ; bitwise or
mov cr0, eax ; place the updated data in to cr0

; 4. far jump seg:addr 
jmp CODE_SEG:init_pm

; set a 32bit code segment
[bits 32]
; init the protected mode
init_pm:
    ; 5. update the segment registers point to data segment
    mov ax, DATA_SEG
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; 6. update the stack position for 32 bit mode
    mov ebp, 0x90000
    mov esp, ebp

    ; 7. call the 32 bit starting label
    call BEGIN_PM