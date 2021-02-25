void dummy_test_entrypoint() {

}

void main() {
    char* graphic_mem = (char*) 0xb8000;
    for (int i = 0; i < 160; i += 2) {
        if (i > 10) {
            graphic_mem[i - 1] = 0x0b;
        }
        graphic_mem[i] = 'X';
    }
}