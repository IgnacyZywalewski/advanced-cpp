#include <iostream>
#include "Lista_2.h"

int main()
{
	//Zadanie 1
	std::vector<std::string> vector = { "11", "1", "2", "10", "ala_10", "ala_1"};
	insertion_sort(vector);
	print_vector(vector);

	//Zadanie 2
	const int n = 5;
	constexpr unsigned long long result = factorial<n>();
	std::cout << "Silnia z " << n << " = " << result << "\n";

	//Zadanie 3
	print_all(1, 1.1, 1.2f, "Hello", '2');
}
