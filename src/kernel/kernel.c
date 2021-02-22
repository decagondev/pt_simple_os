/*
    this will be the c entry point of our kernel
    load this in to some space in ram. 0x1000 (entry point to kernel)
*/
// put some dummy filler function

// here is out entry point
void main() {
    char* graphic_mem = (char*) 0xb8000;
    *graphic_mem = 'A';
}