// Lawrence Hook

#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

void initArrayList(struct ArrayList* list) {
	// printf("Initializing ArrayList\n");
	list->length = 0;
	list->capacity = 0;
	list->contents = 0;
	return;
}

void insert(struct ArrayList* list, long val) {
	// empty list
	if (!list->contents) {
		// printf("Inserting first element to ArrayList\n");
		list->contents = (long *) malloc(sizeof(long));
		list->length = 1;
		list->capacity = 1;
		list->contents[0] = val;
		return;
	}

	// list has reached capacity
	if (list->length == list->capacity) {
		// printf("Doubling capacity: %d to %d\n", list->capacity / 2, list->capacity);
		list->contents = realloc(list->contents, 2*list->capacity*sizeof(long));
		list->capacity = 2*list->capacity;
		list->contents[list->length] = val;
		list->length++;
		return;
	}

	list->contents[list->length] = val;
	list->length++;
	return;
}

