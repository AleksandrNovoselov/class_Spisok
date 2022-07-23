#pragma once
#include "Node.h"

class List
{
	Node* _head;
	Node* _tail;
	int _size;
public:
	List() :_head{ nullptr }, _tail{nullptr}, _size{ 0 } {}
	~List() { clear(); }
	void add(string name, int phoneNumber, string address);
	void print();
	static void printNode(Node* current);
	int getSize(){return _size;	}
	int& operator[](const int index);
	void pop_front();
	void clear();
};

