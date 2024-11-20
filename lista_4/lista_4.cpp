#include <iostream>
#include "Lista_4.h"


int main()
{
	//Zadanie 1
	cpplab::vector<int> vector1;
	vector1.push_back(1);

	cpplab::vector<int> vector2 = vector1;

	cpplab::vector<int> vector3 = std::move(vector1);

	cpplab::vector<int> vector4;
	vector4 = vector2;

	cpplab::vector<int> vector5;
	vector5 = std::move(vector3);
}
