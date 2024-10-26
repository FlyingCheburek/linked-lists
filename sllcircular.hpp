#pragma once
#pragma once
#include "sll.hpp"

namespace Circular {
	template<class T>
	class SinglyList {
	private:
		Singly::Node<T>* tail = nullptr;

	public:
		SinglyList() noexcept;
		SinglyList(const std::forward_list<T>&& list) noexcept;
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

