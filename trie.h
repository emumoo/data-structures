// Lawrence Hook
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

struct trieNode {
	int isWord;
	char c;
	int depth;
	struct trieNode* parent;
	struct ArrayList* children;
};

struct trieNode* initTrieNode(struct trieNode* parent);
