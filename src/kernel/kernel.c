void dummy_test_entrypoint() {

}

char output_char();
char* output_str();

void main() {
    char* graphic_mem = (char*) 0xb8000;
    char x = output_char();
    char* my_string = output_str();
    *graphic_mem = x;
    int j = 0;
    for (int i = 2; i < 36; i += 2) {
        graphic_mem[i] = my_string[j];
        j++;
    }
}