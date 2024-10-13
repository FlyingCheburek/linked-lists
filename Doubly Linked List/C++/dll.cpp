#include "dll.hpp"

template<class T>
Doubly::Node<T>::Node() noexcept {
	next = nullptr;
	pred = nullptr;
}

template<class T>
Doubly::Node<T>::Node(const T data, Doubly::Node<T>* next, Doubly::Node<T>* pred) noexcept {
	this->data = data;
	this->next = next;
	this->pred = pred;
}

template<class T>
Doubly::List<T>::~List() noexcept {
	Doubly::Node<T>* node;
	while (head) {
		node = head->next;
		delete head;
		head = node;
	}
}

template<class T>
Doubly::Node<T> Doubly::List<T>::getHead() const {
	if (!head) throw "Error from Doubly::List<T>::getHead(): tried to dereference null pointer.";
	return *head;
}

template<class T>
Doubly::Node<T> Doubly::List<T>::getTail() const {
	if (!tail) throw "Error from Doubly::List<T>::getTail(): tried to dereference null pointer.";
	return *tail;
}

template<class T>
void Doubly::List<T>::forEach(std::function<void(const T&)> func, const bool&& reverse) const noexcept{
	if (!reverse) {
		for (Doubly::Node<T>* node = head; node; node = node->next) func(node->data);
	}
	else {
		for (Doubly::Node<T>* node = tail; node; node = node->pred) func(node->data);
	}
}

template<class T>
void Doubly::List<T>::pushFront(const T value) noexcept {
	Doubly::Node<T>* node = new Doubly::Node<T>(value, head);
	if (head) {
		head->pred = node;
		head = node;
	}
	else tail = head = node;
}

template<class T>
void Doubly::List<T>::pushBack(const T value) noexcept {
	Doubly::Node<T>* node = new Doubly::Node<T>(value, nullptr, tail);
	if (tail) {
		tail->next = node;
		tail = node;
	}
	else tail = head = node;
}

template<class T>
void Doubly::List<T>::popFront() noexcept {
	if (!head) return;
	if (head == tail) {
		delete head;
		head = tail = nullptr;
		return;
	}
	head = head->next;
	delete head->pred;
	head->pred = nullptr;
}

template<class T>
void Doubly::List<T>::popBack() noexcept {
	if (!tail) return;
	if (head == tail) {
		delete tail;
		head = tail = nullptr;
		return;
	}
	tail = tail->pred;
	delete tail->next;
	tail->next = nullptr;
}

template<class T>
void Doubly::List<T>::deleteWhere(const T value) noexcept{
	if (!head) return;
	if (head->data == value) popFront();
	else if (tail->data == value) popBack();
	else {
		for (Doubly::Node<T>* node = head->next; node != tail; node = node->next) {
			if (node->data == value) {
				node->pred->next = node->next;
				node->next->pred = node->pred;
				delete node;
				return;
			}
		}
	}
}
