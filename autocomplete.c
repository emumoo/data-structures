#include <stdio.h>
#include <stdlib.h>

int main() {
    char c, i, pos = 0;
    char empty[101] = {}; 
    char word[100] = {};
    for (i = 0; i < 100; i++) {
        empty[i] = ' ';
    }
    empty[100] = 0;

    system("/bin/stty raw");
    while (c != 4) {
        c = getchar();
        if (c == 0x7f) {
            pos = pos == 0 ? 0 : pos-1;
        } else if (c == 0x20) {
            pos = 0;
            printf("\n");
        } else {
            if (pos < 100) {
                word[pos] = c;
                pos++;
            }
        }
        word[pos] = 0;
        printf("\r%s", empty);
        printf("\r%s", word);
        //printf("%08x\r", c);
    }
    printf("\n");
    system("/bin/stty cooked");
}

