#pragma once
#include "dll.hpp"

namespace Circular {
	template <class T>
	class DoublyList {
	private:
		Doubly::Node<T>* tail;

	public:
		Doubly::Node<T> getTail() const;
		void forEach(std::function<void(const T&)> func, const bool&& reverse = false) const noexcept;

		void pushFront(const T value) noexcept;
		void pushBack(const T value) noexcept;
		void popFront() noexcept;
		void popBack() noexcept;
		void deleteWhere(const T value) noexcept;

		~DoublyList();
	};
}