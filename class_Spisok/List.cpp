#include "List.h"

void List::add(string name, int phoneNumber, string address)
{
	if (_head == nullptr)
	{
		_head = new Node(name, phoneNumber, address);
	}
	else
	{
		Node* current = _head;

		while (current->_next != nullptr)
		{
			current = current->_next;
		}
		current->_next= new Node(name, phoneNumber, address);
	}
	_size++;
}

void List::print()
{
	Node* current = _head;
	printNode(current);

	while (current->_next != nullptr)
	{
		current = current->_next;
		printNode(current);
	}
}

void List::printNode(Node* current)
{
	cout << current->getName() << " ; " << current->getPhone() << " ; " << current->getAddress() << endl;
}

int& List::operator[](const int index)
{
	int counter{ 0 };
	Node* current = _head;
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
	Node *tmp = _head;
	_head = _head->_next;
	delete tmp;
	_size--;
}

void List::clear()
{
	while (_size)
		pop_front();
}
