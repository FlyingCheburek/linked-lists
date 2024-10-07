#pragma once
#include "csll.h"

typedef struct SLLCircle {
	SLLNode* tail;
} SLLCircle;

void sllcircle_destroy(SLLCircle* list);
void sllcircle_push_front(SLLCircle* list, const int value);
void sllcircle_push_back(SLLCircle* list, const int value);
void sllcircle_pop_front(SLLCircle* list);
void sllcircle_pop_back(SLLCircle* list);
void sllcircle_delete_where(SLLCircle* list, const int value);

