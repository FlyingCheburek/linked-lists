#include "cdllcircle.h"
#include <stdlib.h>
#include <stdio.h>

void dllcircle_destroy(DLLCircle* list){
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

void dllcircle_push_front(DLLCircle* list, const int value){
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

void dllcircle_push_back(DLLCircle* list, const int value){
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

void dllcircle_pop_front(DLLCircle* list){
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

void dllcircle_pop_back(DLLCircle* list){
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

void dllcircle_delete_where(DLLCircle* list, const int value){
	if (!list->tail) return;
	if (list->tail == list->tail->next && list->tail->data == value) {
		free(list->tail);
		list->tail = NULL;
	}
	else if (list->tail->next->data == value) dllcircle_pop_front(list);
	else if (list->tail->data == value) dllcircle_pop_back(list);
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
