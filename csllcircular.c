#include "csllcircular.h"
#include <stdlib.h>

void sllcircular_destroy(SLLCircular* list) {
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
		return;
	}
	SLLNode* head = list->tail->next, * temp = head->next;
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

void sllcircular_push_front(SLLCircular* list, const int value) {
	SLLNode* node = (SLLNode*)malloc(sizeof(SLLNode));
	node->data = value;
	node->next = NULL;
	if (!list->tail) {
		list->tail = node;
		list->tail->next = list->tail;
	}
	else {
		node->next = list->tail->next;
		list->tail->next = node;
	}
}

void sllcircular_push_back(SLLCircular* list, const int value) {
	SLLNode* node = (SLLNode*)malloc(sizeof(SLLNode));
	node->data = value;
	node->next = NULL;
	if (!list->tail) {
		list->tail = node;
		list->tail->next = list->tail;
	}
	else {
		node->next = list->tail->next;
		list->tail->next = node;
		list->tail = node;
	}
}

void sllcircular_pop_front(SLLCircular* list) {
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
	}
	else {
		SLLNode* node = list->tail->next->next;
		free(list->tail->next);
		list->tail->next = node;
	}
}

void sllcircular_pop_back(SLLCircular* list) {
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
	}
	else {
		SLLNode* node = list->tail->next, * head;
		while (node->next != list->tail) {
			node = node->next;
		}
		head = list->tail->next;
		list->tail = node;
		free(list->tail->next);
		list->tail->next = head;
	}
}

void sllcircular_delete_where(SLLCircular* list, const int value) {
	if (!list->tail) return;
	if (list->tail == list->tail->next && list->tail->data == value) {
		free(list->tail);
		list->tail = NULL;
	}
	else if (list->tail->next->data == value) sllcircular_pop_front(list);
	else if (list->tail->data == value) sllcircular_pop_back(list);
	else {
		for (SLLNode* pred = list->tail->next, *curr = pred->next; curr != list->tail; pred = curr, curr = curr->next) {
			if (curr->data == value) {
				pred->next = curr->next;
				free(curr);
				return;
			}
		}
	}
}