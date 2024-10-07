#include "csllcircle.h"
#include <stdlib.h>
#include <stdio.h>

void sllcircle_destroy(SLLCircle* list){
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
		return;
	}
	SLLNode* head = list->tail->next, *end = list->tail, *temp = head->next;
	do {
		free(head);
		head = temp;
		if (temp) temp = temp->next;
	} while (head != end);
	if (end) {
		free(end);
		end = NULL;
	}
}

void sllcircle_push_front(SLLCircle* list, const int value){
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

void sllcircle_push_back(SLLCircle* list, const int value) {
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

void sllcircle_pop_front(SLLCircle* list){
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

void sllcircle_pop_back(SLLCircle* list){
	if (!list->tail) return;
	if (list->tail == list->tail->next) {
		free(list->tail);
		list->tail = NULL;
	}
	else {
		SLLNode* node = list->tail->next, *head;
		while (node->next != list->tail) {
			node = node->next;
		}
		head = list->tail->next;
		list->tail = node;
		free(list->tail->next);
		list->tail->next = head;
	}
}

void sllcircle_delete_where(SLLCircle* list, const int value){
	if (!list->tail) return;
	if (list->tail == list->tail->next && list->tail->data == value) {
		free(list->tail);
		list->tail = NULL;
	}
	else if (list->tail->next->data == value) sllcircle_pop_front(list);
	else if (list->tail->data == value) sllcircle_pop_back(list);
	else {
		for (SLLNode *pred = list->tail->next, *curr = pred->next; curr != list->tail; pred = curr, curr = curr->next) {
			if (curr->data == value) {
				pred->next = curr->next;
				free(curr);
				return;
			}
		}
	}
}
