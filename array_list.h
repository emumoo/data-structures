// Lawrence Hook

#include <stdlib.h>
#include <stdio.h>

struct ArrayList {
	unsigned int length;
	unsigned int capacity;
	int *contents;
};

struct ArrayList* initArrayList();
void insert(struct ArrayList* list, int val);
