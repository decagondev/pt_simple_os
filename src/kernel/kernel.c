#include "../drivers/vga.h"


char output_char();
char* output_str();
extern void somefunction();

void main() {
    clear_screen(RED_ON_WHITE);
    kprint("This is a test\n", 0x34);
    kprint_at_pos("This is a test\n", 10, 20, 0x18);
    // char* graphic_mem = (char*) 0xb8000;
    // somefunction(); // from Assembly
    // char x = output_char(); // from rust
    char* my_string = output_str(); // from C++
    kprint_at_pos(my_string, 4, 4, 0x60);
    // *graphic_mem = x;
    // int j = 0;
    // for (int i = 2; i < 36; i += 2) {
    //     graphic_mem[i] = my_string[j];
    //     j++;
    // }
}