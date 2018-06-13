// Lawrence Hook
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

struct treeNode {
	int val;
	struct treeNode* parent;
	struct ArrayList* children;
};

void initTree(struct treeNode* root);
void addChild(struct treeNode* node, int val);
