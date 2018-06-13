// Lawrence Hook
#pragma once

#include <stdlib.h>
#include "../trie.h"

struct trieNode *autocomplete_trie;

struct trieNode* initAutocompleteTrie();
void completeWord(char* word, char* autocompleted);

/* utils */
char toLowerCase(char c);
char isLetter(char c);
