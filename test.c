// Lawrence Hook

#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "linked_list.h"
#include "tree.h"

void testLinkedList();
void testArrayList();
void testTree();


int main(int argc, char* argv[]) {
	testLinkedList();
	testArrayList();
	testTree();
	return 0;
}

void testTree() {
	printf("\nTesting Tree:\n");

	// tree
	struct treeNode* root = malloc(sizeof(struct treeNode));
	initTree(root);
	addChild(root, 1);
	printf("%d\n", ((struct treeNode*) root->children->contents[0])->val);
	printf("\n");
}

void testArrayList() {
	printf("\nTesting Array List:\n");
	int i = 0;
	struct ArrayList* array_list = malloc(sizeof(struct ArrayList));
	initArrayList(array_list);
	for (i = 0; i < 100; i++) {
		insert(array_list, i);
	}
	for (i = 0; i < array_list->length; i++) {
		printf("%ld ", array_list->contents[i]);
	}
	printf("\n");
}

void testLinkedList() {
	printf("\nTesting Linked List:\n");
	int i = 0;
	struct node* linked_list = 0;
	struct node* tempNode;
	for (i = 99; i >= 0; i--) {
		tempNode = (struct node*) malloc(sizeof(struct node));
		tempNode->val = i;
		if (linked_list) {
			tempNode->next = linked_list;
		} else {
			tempNode->next = 0;
		}
		linked_list = tempNode;
	}
	while (tempNode) {
		printf("%d ", tempNode->val);
		tempNode = tempNode->next;
	}
	printf("\n");
}
