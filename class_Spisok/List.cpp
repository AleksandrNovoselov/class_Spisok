#include "List.h"

void List::add(string name, int phoneNumber, string address)
{
	if (_head == nullptr)
	{
		_head = new Student(name, phoneNumber, address);
		_tail = _head;
	}
	else
	{
		Student* newStud = new Student(name, phoneNumber, address);

		newStud->prev = _tail;
		_tail->next = newStud;
		_tail = newStud;
	}
	_size++;
}

void List::print()
{
	Student* current = _head;
	printNode(current);

	while (current->next != nullptr)
	{
		current = current->next;
		printNode(current);
	}
}

void List::printNode(Student* current)
{
	cout << current->getName() << " ; " << current->getPhone() << " ; " << current->getAddress() << endl;
}

int& List::operator[](int index)
{
	int counter = 0;
	if (index >= _size)
	{
		cout << "Неверный индекс";
		return counter;
	}

	if (index <= _size / 2)
	{
		Student* current = _head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				printNode(current);
				return counter;
			}
			current = current->next;
			counter++;
		}
	}

	else
	{
		counter = _size-1;
		Student* current = _tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				printNode(current);
				return counter;
			}
			current = current->prev;
			counter--;
		}
	}
}

void List::pop_front()
{
	Student *tmp = _head;
	_head = _head->next;
	if(_head!=nullptr)
		_head->prev = nullptr;
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
	current->next = _head;
	_head->prev = current;
	_head = current;
	_size++;
}

void List::insert(string name, int phoneNumber, string address, int index)
{
	if(index>=_size)
	{
		cout << "Неверный индекс";
		return;
	}
		
	if (index == 0)
		pushFront(name, phoneNumber, address);
	else
	{
		Student* studIns = new Student(name, phoneNumber, address);

		Student* studPrev = _head;
		Student* studNext;

		for (int i = 0; i < index-1; i++) {
			studPrev = studPrev->next;
		}
		
		studNext = studPrev->next;

		studIns->next = studNext;
		studIns->prev = studPrev;

		studPrev->next = studIns;
		studNext->prev = studIns;

		_size++;
	}
}

void List::remov(int index)
{
	if (index == 0)
		pop_front();

	else
	{
		Student* current = _head;

		for (int i = 0; i < index ; i++) {
			current = current->next;
		}

		Student* studPrev = current->prev;
		Student* studNext = current->next;

		studPrev->next = studNext;
		studNext->prev = studPrev;

		delete current;

		_size--;
	}

}

void List::pop_back()
{
	Student* current = _tail;
	_tail = _tail->prev;
	delete current;
	_tail->next = nullptr;
	_size--;
}
