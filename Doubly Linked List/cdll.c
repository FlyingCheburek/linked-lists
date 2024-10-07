#include "cdll.h"
#include <stdlib.h>

void dll_destroy(DLL* list){
	DLLNode* node;
	while (list->head) {
		node = list->head->next;
		free(list->head);
		list->head = node;
	}
}

void dll_push_front(DLL* list, const int value){
	DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
	node->data = value;
	node->next = NULL;
	node->pred = NULL;
	if (list->head) {
		node->next = list->head;
		list->head->pred = node;
		list->head = node;
	}
	else list->head = list->tail = node;
}

void dll_push_back(DLL* list, const int value){
	DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
	node->data = value;
	node->next = NULL;
	node->pred = NULL;
	if (list->tail) {
		node->pred = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	else list->head = list->tail = node;
}

void dll_pop_front(DLL* list){
	if (!list->head) return;
	if (list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}
	list->head = list->head->next;
	free(list->head->pred);
	list->head->pred = NULL;
}

void dll_pop_back(DLL* list){
	if (!list->tail) return;
	if (list->tail == list->head) {
		free(list->tail);
		list->head = list->tail = NULL;
		return;
	}
	list->tail = list->tail->pred;
	free(list->tail->next);
	list->tail->next = NULL;
}

void dll_delete_where(DLL* list, const int value){
	if (!list->head) return;
	if (list->head->data == value) dll_pop_front(list);
	else if (list->tail->data == value) dll_pop_back(list);
	else {
		for (DLLNode* node = list->head->next; node != list->tail; node = node->next) {
			if (node->data == value) {
				node->pred->next = node->next;
				node->next->pred = node->pred;
				free(node);
				return;
			}
		}
	}
}
