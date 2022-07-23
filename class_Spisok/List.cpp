#include "List.h"

void List::add(string name, int phoneNumber, string address)
{
	if (_head == nullptr)
	{
		_head = new Student(name, phoneNumber, address);
	}
	else
	{
		Student* current = _head;

		while (current->_next != nullptr)
		{
			current = current->_next;
		}
		current->_next= new Student(name, phoneNumber, address);
	}
	_size++;
}

void List::print()
{
	Student* current = _head;
	printNode(current);

	while (current->_next != nullptr)
	{
		current = current->_next;
		printNode(current);
	}
}

void List::printNode(Student* current)
{
	cout << current->getName() << " ; " << current->getPhone() << " ; " << current->getAddress() << endl;
}

int& List::operator[](const int index)
{
	int counter{ 0 };
	Student* current = _head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			printNode(current);
			return counter;
		}
		current = current->_next;
		counter++;
	}
}

void List::pop_front()
{
	Student *tmp = _head;
	_head = _head->_next;
	delete tmp;
	_size--;
}

void List::clear()
{
	while (_size)
		pop_front();
}

void List::pushFront(string name,int phoneNumber, string address)
{
	Student* current = new Student(name, phoneNumber, address);
	current->_next = _head;
	_head = current;
	_size++;
}

void List::insert(string name, int phoneNumber, string address, int index)
{
	if (index == 0)
		pushFront(name, phoneNumber, address);
	else
	{
		Student* newNode = new Student(name, phoneNumber, address);

		Student* current = _head;
		Student* previous = _head;

		for (int i = 0; i < index; i++) {
			current = current->_next;
		}

		for (int i = index - 1; i < index ; i++) {
			previous = previous->_next;
		}
				
		previous->_next = newNode;
		newNode->_next = current;

		_size++;
	}
}

void List::remov(int index)
{
	if (index == 0)
		pop_front();
	else
	{
		Student* previous = _head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->_next;
		}
		Student* toDelete = previous->_next;
		previous->_next = toDelete->_next;

		delete toDelete;

		_size--;
	}

}

void List::pop_back()
{
	remov(_size-1);
}
