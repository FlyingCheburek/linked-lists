#pragma once
#include "cdll.h"

typedef struct DLLCircular {
	DLLNode* tail;
} DLLCircular;

void dllcircular_push_values(DLLCircular* list, const int* values, const size_t size);
void dllcircular_destroy(DLLCircular* list);
void dllcircular_push_front(DLLCircular* list, const int value);
void dllcircular_push_back(DLLCircular* list, const int value);
void dllcircular_pop_front(DLLCircular* list);
void dllcircular_pop_back(DLLCircular* list);
void dllcircular_delete_where(DLLCircular* list, const int value);
