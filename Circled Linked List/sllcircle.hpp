#pragma once
#include "sll.hpp"

namespace Circle {
	template<class T>
	class SinglyList {
	private:
		Singly::Node<T>* tail;
	
	public:
		Singly::Node<T> getTail() const;
		void forEach(std::function<void(const T&)> func) const noexcept;

		void pushFront(const T value) noexcept;
		void pushBack(const T value) noexcept;
		void popFront() noexcept;
		void popBack() noexcept;
		void deleteWhere(const T value) noexcept;

		~SinglyList();
	};
}
