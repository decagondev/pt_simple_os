void dummy_test_entrypoint() {

}

char output_char();

void main() {
    char* graphic_mem = (char*) 0xb8000;
    char x = output_char();
    *graphic_mem = x;
}