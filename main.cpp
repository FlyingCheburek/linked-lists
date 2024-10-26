extern "C" {
#include "csll.h"
#include "cdll.h"
#include "csllcircular.h"
#include "cdllcircular.h"
};

#include "sll.cpp"
#include "dll.cpp"
#include "sllcircular.cpp"
#include "dllcircular.cpp"

#include <iostream>

int main() {
	SLLNode sllnode = { 0, 0 };
	SLL sll = { 0, 0 };
	Singly::Node<int> _sllnode;
	Singly::List<int> _sll;

	DLLNode dllnode = { 0, 0, 0 };
	DLL dll = { 0, 0 };
	Doubly::Node<int> _dllnode;
	Doubly::List<int> _dll;

	SLLCircular sllcircle = { 0 };
	Circular::SinglyList<int> _sllcircle;

	DLLCircular dllcircle = { 0 };
	Circular::DoublyList<int> _dllcircle;
	return 0;
}