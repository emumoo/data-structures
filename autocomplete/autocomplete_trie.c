// Lawrence Hook

#include <stdlib.h>
#include <stdio.h>
#include "../trie.h"
#include "autocomplete_trie.h"

#define words_file "/usr/share/dict/words"

struct trieNode* initAutocompleteTrie() {
	int i;
	struct trieNode *currNode;
	autocomplete_trie = initTrieNode(0);

	char buff[100], currLetter;
	FILE *words = fopen(words_file, "r");
	while(fgets(buff, 255, words) != NULL) {
		i = 0;
		currNode = autocomplete_trie;
		while (buff[i] != 0) {
			currLetter = toLowerCase(buff[i]);

			if (currLetter == 0xa) { // newline
				// printf("\newline");
				currNode->isWord = 1;
			} else {
				// printf("%c", currLetter);
				if (!isLetter(currLetter)) break;

				if (currNode->children->contents[currLetter-97] == 0) {
					currNode->children->contents[currLetter-97] = (long) initTrieNode(currNode);
					currNode = (struct trieNode*) currNode->children->contents[currLetter-97];
					currNode->c = currLetter;
					currNode->depth = i;
				} else {
					currNode = (struct trieNode*) currNode->children->contents[currLetter-97];
				}
			}
			i++;
		}
	}
	fclose(words);

	return (struct trieNode*) 0;
}


void completeWord(char* word, char* autocompleted) {
	int i = 0;
	// int doneSearching = 0;
	char currLetter;
	struct trieNode *currNode = autocomplete_trie;

	struct ArrayList* q = malloc(sizeof(struct ArrayList));
	initArrayList(q);
	int qPos = 0;

	// navigate to `word` in the trie
	while (word[i] != 0) {
		currLetter = toLowerCase(word[i]);
		if (!isLetter(currLetter) || 
			currNode->children->contents[currLetter-97] == 0) {
			autocompleted[0] = 0;
			return;
		}

		autocompleted[i] = currLetter;
		currNode = (struct trieNode*) currNode->children->contents[currLetter-97];
		i++;
	}


	// find the closest word to `word` in the trie
	struct trieNode* child;
	while (!currNode->isWord) {
		for (i = 0; i < 26; i++) {
			child = (struct trieNode*) currNode->children->contents[i];
			if (child) {
				if (child->isWord) {
					currNode = child;
					break;
				} else {
					insert(q, (long) child);
				}
			}
		}

		if (qPos < q->length) {
			currNode = (struct trieNode*) q->contents[qPos];
			qPos++;
		} else {
			break;
		}
	}

	autocompleted[currNode->depth + 1] = 0;
	while (currNode->parent) {
		autocompleted[currNode->depth] = currNode->c;
		currNode = currNode->parent;
	}
}

/* utils */
char toLowerCase(char c) {
	if (c >= 65 && c <= 90) {
		c += 32;
	}
	return c;
}

char isLetter(char c) {
	return c >= 97 && c <= 122;
}