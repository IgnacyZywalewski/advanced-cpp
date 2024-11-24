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

	std::cout << "\n";

	//Zadanie 2
	cpplab::vector<Pixel> vector_pixel;
	vector_pixel.emplace_back(3, 4, 5);
	vector_pixel.emplace_back(1);
	vector_pixel.emplace_back(6, 7, 8);
	print_vector(vector_pixel);

	std::cout << "\n";
}
