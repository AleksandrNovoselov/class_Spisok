#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
	string _name;
	int _phoneNumber;
	string _address;
public:
	Student() {
		_phoneNumber = 0;
		_next = nullptr;
		_prev = nullptr;
	}
	Student(string name, int phoneNumber, string address) :
		_name{ name }, _phoneNumber{ phoneNumber }, _address{ address }, _next{ nullptr }{}
	~Student() {}

	Student* _next;
	Student* _prev;

	string getName() {return _name;}
	int getPhone() const {return _phoneNumber;}
	string getAddress()	{return _address;}
};

