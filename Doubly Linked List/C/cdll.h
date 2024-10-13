#pragma once

typedef struct DLLNode {
    int data;
    struct DLLNode* next, *pred;
} DLLNode;

typedef struct DLL {
    DLLNode* head, * tail;
} DLL;

void dll_destroy(DLL* list);
void dll_push_front(DLL* list, const int value);
void dll_push_back(DLL* list, const int value);
void dll_pop_front(DLL* list);
void dll_pop_back(DLL* list);
void dll_delete_where(DLL* list, const int value);
