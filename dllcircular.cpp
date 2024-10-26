#include "dllcircular.hpp"

template<class T>
Doubly::Node<T> Circular::DoublyList<T>::getTail() const {
	if (!tail) throw "Error from Circle::DoublyList<T>::getTail(): tried to dereference null pointer.";
	return *tail;
}

template<class T>
void Circular::DoublyList<T>::forEach(std::function<void(const T&)> func, const bool&& reverse) const noexcept {
	if (!tail) return;
	if (tail == tail->next) func(tail->data);
	else {
		Doubly::Node<T>* node = reverse ? tail : tail->next;
		do {
			func(node->data);
			node = reverse ? node->pred : node->next;
		} while (node != (reverse ? tail : tail->next));
	}
}

template<class T>
void Circular::DoublyList<T>::pushFront(const T value) noexcept {
	if (!tail) {
		tail = new Doubly::Node<T>(value);
		tail->next = tail->pred = tail;
	}
	else {
		Doubly::Node<T>* node = new Doubly::Node<T>(value, tail->next, tail);
		tail->next->pred = node;
		tail->next = node;
	}
}

template<class T>
void Circular::DoublyList<T>::pushBack(const T value) noexcept {
	Doubly::Node<T>* node = new Doubly::Node<T>(value);
	if (!tail) {
		tail = node;
		tail->next = tail->pred = tail;
	}
	else {
		node->next = tail->next;
		tail->next->pred = node;
		node->pred = tail;
		tail->next = node;
		tail = node;
	}
}

template<class T>
void Circular::DoublyList<T>::popFront() noexcept {
	if (!tail) return;
	if (tail == tail->next) {
		delete tail;
		tail = nullptr;
	}
	else {
		Doubly::Node<T>* new_head = tail->next->next;
		new_head->pred = tail;
		delete tail->next;
		tail->next = new_head;
	}
}

template<class T>
void Circular::DoublyList<T>::popBack() noexcept {
	if (!tail) return;
	if (tail == tail->next) {
		delete tail;
		tail = nullptr;
	}
	else {
		Doubly::Node<T>* new_tail = tail->pred;
		tail->next->pred = new_tail;
		new_tail->next = tail->next;
		delete tail;
		tail = new_tail;
	}
}

template<class T>
void Circular::DoublyList<T>::deleteWhere(const T value) noexcept {
	if (!tail) return;
	if (tail == tail->next && tail->data == value) {
		delete tail;
		tail = nullptr;
	}
	else if (tail->next->data == value) popFront();
	else if (tail->data == value) popBack();
	else {
		Doubly::Node<T>* node = tail->next;
		do {
			if (node->data == value) {
				node->pred->next = node->next;
				node->next->pred = node->pred;
				delete node;
				return;
			}
			node = node->next;
		} while (node != tail->next);
	}
}

template<class T>
Circular::DoublyList<T>::~DoublyList() {
	if (!tail) return;
	if (tail == tail->next) {
		delete tail;
		tail = nullptr;
		return;
	}
	Doubly::Node<T>* head = tail->next, * temp = head->next;
	do {
		delete head;
		head = temp;
		if (temp) temp = temp->next;
	} while (head != tail);
	if (tail) {
		delete tail;
		tail = nullptr;
	}
}