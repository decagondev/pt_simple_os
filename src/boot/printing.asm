; stuff to print to the screen

; function to print a line to the screen using the string at bx
println:
    pusha ; store the state of the cpu registers on the stack
    mov ah, 0x0e ; set tty mode write char

    ; loop over put character on screen
    print_char:
        mov al, [bx] ; put the char at bx in to al
        cmp al, 0
        je done

        int 0x10 ; call the video interrupt to write the char

        add bx, 1 ; increment the bx pointer to point to the next character
        jmp print_char


    done:
        call print_newline
        popa ; restore all of the cpu register state
        ret

print_newline:
    pusha ; store the state of the cpu registers on the stack
    
    mov ah, 0x0e ; set tty mode write char
    mov al, 0x0a ; new line character
    int 0x10 ; wite the character
    mov al, 0x0d ; carriage return character
    int 0x10 ; write the character

    popa ; restore all of the cpu register state
    ret