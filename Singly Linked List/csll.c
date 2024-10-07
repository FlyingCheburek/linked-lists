#include "csll.h"
#include <stdlib.h>

void sll_destroy(SLL* list) {
	SLLNode* node;
	while (list->head) {
		node = list->head->next;
		free(list->head);
		list->head = node;
	}
}

void sll_push_front(SLL* list, const int value) {
	SLLNode* n = (SLLNode*)malloc(sizeof(SLLNode));
	n->data = value;
	n->next = list->head;
	list->head = n;
	if (!list->tail) list->tail = list->head;
}

void sll_push_back(SLL* list, const int value) {
	SLLNode* n = (SLLNode*)malloc(sizeof(SLLNode));
	n->data = value;
	n->next = NULL;
	if (list->tail) {
		list->tail->next = n;
		list->tail = n;
	}
	else list->head = list->tail = n;
}

void sll_pop_front(SLL* list) {
	if (!list->head) return;
	if (list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}
	SLLNode* node = list->head->next;
	free(list->head);
	list->head = node;
}

void sll_pop_back(SLL* list) {
	if (!list->tail) return;
	if (list->head == list->tail) {
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}
	SLLNode* node = list->head;
	for (; node->next != list->tail; node = node->next);
	free(list->tail);
	node->next = NULL;
	list->tail = node;
}

void sll_delete_where(SLL* list, const int value) {
	if (!list->head) return;
	if (list->head == list->tail && list->head->data == value) {
		free(list->head);
		list->head = list->tail = NULL;
	}
	else if (list->head->data == value) {
		SLLNode* node = list->head->next;
		free(list->head);
		list->head = node;
	}
	else if (list->tail->data == value) sll_pop_back(list);
	else {
		for (SLLNode* pred = list->head, *curr = list->head->next; curr; pred = curr, curr = curr->next) {
			if (curr->data == value) {
				pred->next = curr->next;
				free(curr);
				return;
			}
		}
	}
}
