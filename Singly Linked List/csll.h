#pragma once

typedef struct SLLNode {
    int data;
    struct SLLNode* next;
} SLLNode;

typedef struct SLL {
    SLLNode* head, * tail;
} SLL;

void sll_destroy(SLL* list);
void sll_push_front(SLL* list, const int value);
void sll_push_back(SLL* list, const int value);
void sll_pop_front(SLL* list);
void sll_pop_back(SLL* list);
void sll_delete_where(SLL* list, const int value); 
