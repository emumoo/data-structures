// Lawrence Hook

#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "linked_list.h"


int main(int argc, char* argv[]) {
	int i = 0;

	// Linked List
	struct node* linked_list = 0;
	struct node* tempNode;
	for (i = 100; i >= 0; i--) {
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
		printf("%d", tempNode->val);
		tempNode = tempNode->next;
	}
	printf("\n");

	// ArrayList
	struct ArrayList* array_list = initArrayList();
	for (i = 0; i < 1000; i++) {
		insert(array_list, i);
	}

	return 0;
}

// // linked list
// int main(int argc, char* argv[]) {
// 	int i = 0;
// 	struct node* list = 0;
// 	struct node* tempNode;

// 	for (i = 100; i >= 0; i--) {
// 		tempNode = (struct node*) malloc(sizeof(struct node));
// 		tempNode->val = i;
// 		if (list) {
// 			tempNode->next = list;
// 		} else {
// 			tempNode->next = 0;
// 		}
// 		list = tempNode;
// 	}

// 	tempNode = list;
// 	while (tempNode) {
// 		printf("%d\n", tempNode->val);
// 		tempNode = tempNode->next;
// 	}

// 	return 0;
// }

// // array list
// int main(int argc, char *argv[]) {
// 	struct ArrayList* list = initArrayList();
// 	int i = 0;

// 	for (i = 0; i < 1000; i++) {
// 		insert(list, i);
// 	}

// 	// for (i = 0; i < list->length; i++) {
// 	// 	printf("%d\n", list->contents[i]);
// 	// }

// 	return 0;
// }