; load some sectors from disk (dh) <= num sectors to load (dl) <= drive load in to ES:BX
disk_load:
    pusha ; store the state of the cpu registers on the stack
    push dx

    mov ah, 0x02 ; BIOS Function Read Disk Sector 0x02
    mov al, dh ; number of sectors to read
    mov cl, 0x02 ; sector 2
    mov ch, 0x00 ; cylinder 0
    mov dh, 0x00 ; head 0

    int 0x13 ; read interrupt
    
    jc disk_error

    pop dx
    cmp al, dh
    jne sector_error
    popa ; restore all of the cpu register state
    ret


disk_error:
    ; do some stuff
    mov bx, DISK_ERROR
    call println
    ; TODO: get error code and print in HEX (write a print hex function)
    jmp disk_loop

sector_error:
    ; do stuff for wrong number of sectors read
    mov bx, SECTORS_ERROR
    call println


disk_loop:
    jmp $


; data
DISK_ERROR: db 'Error Reading Disk', 0
SECTORS_ERROR: db 'Incorrect Number of Sectors Read', 0