#pragma once
#include "csll.h"

typedef struct SLLCircular {
	SLLNode* tail;
} SLLCircular;

void sllcircular_destroy(SLLCircular* list);
void sllcircular_push_front(SLLCircular* list, const int value);
void sllcircular_push_back(SLLCircular* list, const int value);
void sllcircular_pop_front(SLLCircular* list);
void sllcircular_pop_back(SLLCircular* list);
void sllcircular_delete_where(SLLCircular* list, const int value);
