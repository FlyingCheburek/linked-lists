#pragma once
#include <functional>

namespace Singly {
	template<class T>
	struct Node {
		T data;
		Node<T>* next;
		Node() noexcept;
		Node(const T data, Node<T>* next = nullptr) noexcept;
	};

	template<class T>
	class List {
	private:
		Node<T>* head, * tail;

	public:
		Node<T> getHead() const;
		Node<T> getTail() const;
		void forEach(std::function<void(const T&)> func) const noexcept;
		void pushFront(const T value) noexcept;
		void pushBack(const T value) noexcept;
		void popFront() noexcept;
		void popBack() noexcept;
		void deleteWhere(const T value) noexcept;
		~List() noexcept;
	};
}