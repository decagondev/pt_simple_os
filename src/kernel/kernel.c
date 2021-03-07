#include "../drivers/sys.h"

char output_char();
char* output_str();
extern void somefunction();

void main() {
    char* graphic_mem = (char*) 0xb8000;
    outportb(0x3d4, 14); // request the high byte of the cursor position from the VGA Control Register
    int pos_hi = inportb(0x3d5); // save data from the VGA Data Register to pos_hi variable
    somefunction(); // from Assembly
    char x = output_char(); // from rust
    char* my_string = output_str(); // from C++
    *graphic_mem = x;
    int j = 0;
    for (int i = 2; i < 36; i += 2) {
        graphic_mem[i] = my_string[j];
        j++;
    }
}