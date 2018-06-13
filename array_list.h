// Lawrence Hook
#pragma once

#include <stdlib.h>
#include <stdio.h>

struct ArrayList {
	unsigned int length;
	unsigned int capacity;
	long *contents;
};

void initArrayList(struct ArrayList* list);
void insert(struct ArrayList* list, long val);
