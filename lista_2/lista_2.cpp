#include <iostream>
#include "Lista_2.h"

int main()
{
	//Zadanie 1
	//std::vector<std::string> vector_s = { "batman", "bat", "apple" };
	std::vector<std::string> vector_s = { "12", "11", "1", "123", "ala", "ale" };
	insertion_sort(vector_s);
	print_vector(vector_s);

	/*
	std::vector<int> vector_i = { 123, 12, 11, 1 };
	insertion_sort(vector_i);
	print_vector(vector_i);
	*/
}
