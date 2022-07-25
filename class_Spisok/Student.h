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
		next = nullptr;
		prev = nullptr;
	}
	Student(string name, int phoneNumber, string address) :
		_name{ name }, _phoneNumber{ phoneNumber }, _address{ address }, next{ nullptr }{}
	~Student() {}

	Student* next;
	Student* prev;

	string getName() {return _name;}
	int getPhone() const {return _phoneNumber;}
	string getAddress()	{return _address;}
};

