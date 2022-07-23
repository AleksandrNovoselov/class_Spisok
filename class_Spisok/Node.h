#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node
{
	string _name;
	int _phoneNumber;
	string _address;
public:
	Node() {
		_phoneNumber = 0;
		_next = nullptr;
		_prev = nullptr;
	}
	Node(string name, int phoneNumber, string address) :
		_name{ name }, _phoneNumber{ phoneNumber }, _address{ address }, _next{ nullptr }{}
	~Node() {}

	Node* _next;
	Node* _prev;

	string getName() {return _name;}
	int getPhone() const {return _phoneNumber;}
	string getAddress()	{return _address;}
};

