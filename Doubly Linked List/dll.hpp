#pragma once
#include <functional>

namespace Doubly {
	template<class T>
	struct Node {
		T data;
		Node<T>* next, *pred;

		Node() noexcept;
		Node(const T data, Node<T>* next = nullptr, Node<T>* pred = nullptr) noexcept;
	};

	template<class T>
	class List {
	private:
		Node<T>* head = nullptr, * tail = nullptr;

	public:
		~List() noexcept;

		Node<T> getHead() const;
		Node<T> getTail() const; 
		void forEach(std::function<void(const T&)> func, const bool&& reverse = false) const noexcept;
		void pushFront(const T value) noexcept;
		void pushBack(const T value) noexcept;
		void popFront() noexcept;
		void popBack() noexcept;
		void deleteWhere(const T value) noexcept;
	};
}
