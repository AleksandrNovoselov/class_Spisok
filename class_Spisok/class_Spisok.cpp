﻿#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	//односвязный список, запись студентов пока в упрощенном виде
	setlocale(LC_ALL,"ru");
    List list;
	for (size_t i = 0; i < 10; i++)
	{
		list.add("Student", i, "Izhevsk");
	}

	list.pushFront("Nachalo", 55, "Moskva");

	list.insert("Insert", 22, "Moskva", 2);

	list.print();

	cout <<"вывод на печать указанного элемента" <<endl;
	list[5];
	cout<<list.getSize();
	cout << endl;

	cout << "удаление указанного элемента" << endl;
	list.remov(2);
	list.print();

	cout << "удаление последнего элемента" << endl;
	list.pop_back();
	list.print();

}

