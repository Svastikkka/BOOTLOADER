// Simple integer to string conversion
void itoa(int num, char *str) {
    int i = 0;
    int is_negative = 0;

    if(num == 0){
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0){
        is_negative = 1;
        num = -num;
    }

    while(num > 0){
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    if(is_negative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    // Reverse string
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}
// Print to screen
void print(char *str) {
    char *video = (char*) 0xB8000;
    for (int i = 0; str[i] != '\0'; i++) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x07;
    }
}
// Main logic
void c_main() {
    int a = 10;
    int b = 5;
    int sum = a + b;
    int mul = a * b;
    int sub = a - b;
    int div = a / b;
    char buffer[20];
    print("ADD: ");
    itoa(sum, buffer);
    print(buffer);
    // Move cursor manually by offset (simple trick)
    char *video = (char*) 0xB8000;
    int offset = 160; // next line
    // SUB
    itoa(sub, buffer);
    video[offset + 0] = 'S';
    video[offset + 2] = 'U';
    video[offset + 4] = 'B';
    video[offset + 6] = ':';
    video[offset + 8] = ' ';
    for (int i = 0; buffer[i]; i++) {
        video[offset + 10 + i * 2] = buffer[i];
        video[offset + 11 + i * 2] = 0x07;
    }
    while (1);
}
