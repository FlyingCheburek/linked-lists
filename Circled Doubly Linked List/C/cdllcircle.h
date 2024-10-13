#pragma once
#include "cdll.h"

typedef struct DLLCircle {
	DLLNode* tail;
} DLLCircle;

void dllcircle_destroy(DLLCircle* list);
void dllcircle_push_front(DLLCircle* list, const int value);
void dllcircle_push_back(DLLCircle* list, const int value);
void dllcircle_pop_front(DLLCircle* list);
void dllcircle_pop_back(DLLCircle* list);
void dllcircle_delete_where(DLLCircle* list, const int value);
