// Lawrence Hook

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


void initTree(struct treeNode* root) {
	root->val = 0;
	root->parent = 0;
	root->children = malloc(sizeof(struct ArrayList));
	initArrayList(root->children);
}

void addChild(struct treeNode* node, int val) {
	struct treeNode* child = malloc(sizeof(struct treeNode));
	child->parent = node;
	child->val = val;
	child->children = malloc(sizeof(struct ArrayList));
	initArrayList(child->children);

	insert(node->children, (long) child);
}