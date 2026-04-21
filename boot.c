void print(char *str) {
    char *video = (char*) 0xB8000;  // VGA text buffer

    for (int i = 0; str[i] != '\0'; i++) {
        video[i * 2] = str[i];      // Character
        video[i * 2 + 1] = 0x07;    // Attribute (white text)
    }
}

void c_main() {
    print("Hello from C Bootloader!");
    
    while (1); // Infinite loop
}