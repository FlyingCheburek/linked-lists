extern "C" {
	#include "csll.h"
	#include "cdll.h"
    #include "csllcircle.h"
	#include "cdllcircle.h"
};

#include "sll.cpp"
#include "dll.cpp"
#include "sllcircle.cpp"
#include "dllcircle.cpp"

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

	SLLCircle sllcircle = { 0 };
	Circle::SinglyList<int> _sllcircle;

	DLLCircle dllcircle = { 0 };
	Circle::DoublyList<int> _dllcircle;
	return 0;
}