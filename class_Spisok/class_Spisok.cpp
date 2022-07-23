#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main()
{
    List list;
	for (size_t i = 0; i < 10; i++)
	{
		list.add("Name", i, "Izhevsk");
	}
	list.print();
	cout << endl;
	list[2];
}

