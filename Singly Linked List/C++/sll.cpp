#include "sll.hpp"

template<class T>
Singly::Node<T>::Node() noexcept {
	next = nullptr;
}

template<class T>
Singly::Node<T>::Node(const T data, Singly::Node<T>* next) noexcept {
	this->data = data;
	this->next = next;
}

template<class T>
Singly::Node<T> Singly::List<T>::getHead() const {
	if (!head) throw "Error from Singly::List<T>::getHead(): tried to dereference null pointer.";
	return *head;
}

template<class T>
Singly::Node<T> Singly::List<T>::getTail() const {
	if (!tail) throw "Error from Singly::List<T>::getTail(): tried to dereference null pointer.";
	return *tail;
}

template<class T>
void Singly::List<T>::forEach(std::function<void(const T&)> func) const noexcept {
	for (Singly::Node<T>* node = head; node; node = node->next) func(node->data);
}

template<class T>
void Singly::List<T>::pushFront(const T value) noexcept {
	head = new Singly::Node<T>(value, head);
	if (!tail) tail = head;
}

template<class T>
void Singly::List<T>::pushBack(const T value) noexcept {
	if (tail) {
		tail->next = new Singly::Node<T>(value);
		tail = tail->next;
	}
	else {
		head = tail = new Singly::Node<T>(value);
	}
}

template<class T>
void Singly::List<T>::popFront() noexcept {
	if (!head) return;
	Singly::Node<T>* node;
	if (head == tail) {
		delete head;
		tail = head = nullptr;
	}
	else {
		node = head->next;
		delete head;
		head = node;
	}
}

template<class T>
void Singly::List<T>::popBack() noexcept {
	if (!tail) return;
	if (tail == head) {
		delete tail;
		head = tail = nullptr;
	}
	else {
		Singly::Node<T>* new_tail = head;
		for (; new_tail->next != tail; new_tail = new_tail->next);
		delete tail;
		tail = new_tail;
		tail->next = nullptr;
	}
}

template<class T>
void Singly::List<T>::deleteWhere(const T value) noexcept {
	if (!head) return;
	if (head == tail && head->data == value) {
		delete head;
		head = tail = nullptr;
	}
	else if (head->data == value) {
		Singly::Node<T>* node = head->next;
		delete head;
		head = node;
	}
	else if (tail->data == value) popBack();
	else {
		for (Singly::Node<T>* pred = head, *curr = head->next; curr; pred = curr, curr = curr->next) {
			if (curr->data == value) {
				pred->next = curr->next;
				delete curr;
				return;
			}
		}
	}
}

template<class T>
Singly::List<T>::~List() noexcept {
	Singly::Node<T>* node;
	while (head) {
		node = head->next;
		delete head;
		head = node;
	}
}