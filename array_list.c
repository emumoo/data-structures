// Lawrence Hook

#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

// struct ArrayList {
// 	unsigned int length;
// 	unsigned int capacity;
// 	int *contents;
// };

struct ArrayList* initArrayList() {
	struct ArrayList* list = malloc(sizeof(struct ArrayList*));
	list->length = 0;
	list->capacity = 0;
	list->contents = 0;
	printf("Initializing ArrayList\n");
	return list;
}

void insert(struct ArrayList* list, int val) {
	// empty list
	if (!list->contents) {
		list->contents = (int *) malloc(sizeof(int));
		list->length = 1;
		list->capacity = 1;
		list->contents[0] = val;
		printf("Inserting first element to ArrayList\n");
		return;
	}

	// list has reached capacity
	if (list->length == list->capacity) {
		list->contents = realloc(list->contents, 2*list->capacity*sizeof(int));
		list->capacity = 2*list->capacity;
		list->contents[list->length] = val;
		list->length++;
		printf("Doubling capacity: %d to %d\n", list->capacity / 2, list->capacity);
		return;
	}

	list->contents[list->length] = val;
	list->length++;
	return;
}
