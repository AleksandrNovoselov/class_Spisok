#pragma once
#include "Student.h"

class List
{
	Student* _head;
	Student* _tail;
	int _size;
public:
	List() :_head{ nullptr }, _tail{ nullptr }, _size{ 0 } {}
	~List() { clear(); }

	void add(string name, int phoneNumber, string address);

	void print();
	static void printNode(Student* current);

	int getSize(){return _size;	}
	int& operator[](const int index);

	void pop_front();

	void clear();

	void pushFront(string name, int phoneNumber,  string address);

	void insert(string name, int phoneNumber, string address, int index);

	void remov(int index);

	void pop_back();
};

