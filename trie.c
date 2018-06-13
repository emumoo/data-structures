// Lawrence Hook

#include <stdlib.h>
#include "trie.h"

struct trieNode* initTrieNode(struct trieNode* parent) {
	struct trieNode *node = malloc(sizeof(struct trieNode));
	node->isWord = 0;
	node->c = 0;
	node->depth = -1;
	node->parent = parent;
	node->children = malloc(sizeof(struct ArrayList));
	initArrayList(node->children);

	int i = 0;
	for (i = 0; i < 26; i++) {
		insert(node->children, 0);
	}
	return node;
}
