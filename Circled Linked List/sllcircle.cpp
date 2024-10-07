#include "sllcircle.hpp"

template<class T>
Singly::Node<T> Circle::SinglyList<T>::getTail() const {
	if (!tail) throw "Error from Circle::SinglyList<T>::getTail(): tried to dereference null pointer.";
	return *tail;
}

template<class T>
void Circle::SinglyList<T>::forEach(std::function<void(const T&)> func) const noexcept{
	if (!tail) return;
	if (tail == tail->next) func(tail->next->data);
	else {
		Singly::Node<T>* node = tail->next;
		while (node != tail) {
			func(node->data);
			node = node->next;
		}
		func(node->data);
	}
}

template<class T>
void Circle::SinglyList<T>::pushFront(const T value) noexcept {
	if (!tail) {
		tail = new Singly::Node<T>(value);
		tail->next = tail;
	}
	else {
		Singly::Node<T>* node = new Singly::Node<T>(value, tail->next);
		tail->next = node;
	}
}

template<class T>
void Circle::SinglyList<T>::pushBack(const T value) noexcept {
	Singly::Node<T>* node = new Singly::Node<T>(value);
	if (!tail) {
		tail = node;
		tail->next = tail;
	}
	else {
		node->next = tail->next;
		tail = tail->next = node;
	}
}

template<class T>
void Circle::SinglyList<T>::popFront() noexcept {
	if (!tail) return;
	if (tail == tail->next) {
		delete tail;
		tail = nullptr;
	}
	else {
		Singly::Node<T>* node = tail->next->next;
		delete tail->next;
		tail->next = node;
	}
}

template<class T>
void Circle::SinglyList<T>::popBack() noexcept {
	if (!tail) return;
	if (tail == tail->next) {
		delete tail;
		tail = nullptr;
	}
	else {
		Singly::Node<T>* temp = tail->next, * head = temp;
		while (temp->next != tail) temp = temp->next;
		tail = temp;
		delete tail->next;
		tail->next = head;
	}
}

template<class T>
void Circle::SinglyList<T>::deleteWhere(const T value) noexcept {
	if (!tail) return;
	if (tail == tail->next && tail->data == value) {
		delete tail;
		tail = nullptr;
	}
	else if (tail->data == value) popBack();
	else if (tail->next->data == value) popFront();
	else {
		for (Singly::Node<T>* pred = tail->next, *curr = pred->next; curr != tail; pred = curr, curr = curr->next) {
			if (curr->data == value) {
				pred->next = curr->next;
				delete curr;
				return;
			}
		}
	}
}

template <class T>
Circle::SinglyList<T>::~SinglyList() {
	if (!tail) return;
	if (tail == tail->next) {
		delete tail;
		tail = nullptr;
		return;
	}
	Singly::Node<T>* head = tail->next, * temp = head->next;
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