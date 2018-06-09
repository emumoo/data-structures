// Lawrence Hook

#include <stdlib.h>
#include <stdio.h>


struct treeNode {
	int val;
	struct treeNode* parent;
	struct treeNode* children[];
};

