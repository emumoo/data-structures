#include <stdio.h>
#include <stdlib.h>

#include "../array_list.h"
#include "../linked_list.h"
#include "../tree.h"
#include "autocomplete_trie.h"

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main() {
    int i, pos = 0;
    char c = 0;
    char empty[101] = {}; 
    char word[100] = {};
    char autocompleted[100] = {};

    for (i = 0; i < 100; i++) {
        empty[i] = ' ';
    }
    empty[100] = 0;

    initAutocompleteTrie();

    system("/bin/stty raw");
    while (c != 4) {
        c = getchar();
        if (c == 0x7f) { // backspace character
            pos = pos == 0 ? 0 : pos-1;
        } else if (c == 0x20) { // space character
            pos = 0;
            printf("\n");
        } else {
            if (pos < 100) {
                word[pos] = c;
                pos++;
            }
        }
        word[pos] = 0;

        completeWord(word, autocompleted);

        printf("\r%s", empty);
        printf("\r\033[%dC", 20); // Move right x columns;
        printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET, autocompleted);
        printf("\r%s\n", word);
        printf("\033[%dA", 1); // move cursor up x lines

        // printf("%08x\r", c);
    }
    printf("\n\r");
    system("/bin/stty cooked");
}
