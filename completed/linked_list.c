// Lawrence Hook


#include <stdlib.h>
#include <stdio.h>

struct node {
	int val;
	struct node *next;
};

int main(int argc, char* argv[]) {
	int i = 0;
	struct node* list = 0;
	struct node* tempNode;

	for (i = 100; i >= 0; i--) {
		tempNode = (struct node*) malloc(sizeof(struct node));
		tempNode->val = i;
		if (list) {
			tempNode->next = list;
		} else {
			tempNode->next = 0;
		}
		list = tempNode;
	}

	tempNode = list;
	while (tempNode) {
		printf("%d\n", tempNode->val);
		tempNode = tempNode->next;
	}

	return 0;
}