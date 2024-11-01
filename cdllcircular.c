#include "cdllcircular.h"
#include <stdlib.h>
#include <stdio.h>

void dllcircular_push_values(DLLCircular* list, const int* values, const size_t size){
	for (size_t x = 0; x < size; x++) dllcircular_push_back(list, values[x]);
}

void dllcircular_destroy(DLLCircular* list) {
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
		return;
	}
	DLLNode* head = list->tail->next, * temp = head->next;
	do {
		free(head);
		head = temp;
		if (temp) temp = temp->next;
	} while (head != list->tail);
	if (list->tail) {
		free(list->tail);
		list->tail = NULL;
	}
}

void dllcircular_push_front(DLLCircular* list, const int value) {
	DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
	node->data = value;
	node->next = NULL;
	node->pred = NULL;
	if (!list->tail) {
		list->tail = node;
		node->next = list->tail;
		node->pred = list->tail;
	}
	else {
		node->next = list->tail->next;
		node->pred = list->tail;
		list->tail->next->pred = node;
		list->tail->next = node;
	}
}

void dllcircular_push_back(DLLCircular* list, const int value) {
	DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
	node->data = value;
	node->next = NULL;
	node->pred = NULL;
	if (!list->tail) {
		list->tail = node;
		node->next = list->tail;
		node->pred = list->tail;
	}
	else {
		node->next = list->tail->next;
		list->tail->next->pred = node;
		node->pred = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
}

void dllcircular_pop_front(DLLCircular* list) {
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
	}
	else {
		DLLNode* new_head = list->tail->next->next;
		new_head->pred = list->tail;
		free(list->tail->next);
		list->tail->next = new_head;
	}
}

void dllcircular_pop_back(DLLCircular* list) {
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
	}
	else {
		DLLNode* new_tail = list->tail->pred;
		list->tail->next->pred = new_tail;
		new_tail->next = list->tail->next;
		free(list->tail);
		list->tail = new_tail;
	}
}

void dllcircular_delete_where(DLLCircular* list, const int value) {
	if (!list->tail) return;
	if (list->tail == list->tail->next && list->tail->data == value) {
		free(list->tail);
		list->tail = NULL;
	}
	else if (list->tail->next->data == value) dllcircular_pop_front(list);
	else if (list->tail->data == value) dllcircular_pop_back(list);
	else {
		DLLNode* node = list->tail->next;
		do {
			if (node->data == value) {
				node->pred->next = node->next;
				node->next->pred = node->pred;
				free(node);
				return;
			}
			node = node->next;
		} while (node != list->tail->next);
	}
}