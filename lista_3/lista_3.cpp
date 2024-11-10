#include <iostream>
#include <string>
#include "Lista_3.h"


int main()
{
    //Zadanie 1
	std::vector<float> vector1 = { 1.5f, 2.5f, 3.5f };
	cpplab::vector<int> vector2;
	vector2.push_back(1);
	vector2.push_back(2);
	vector2.push_back(3);

	std::cout << "Iloczyn skalarny wektorow std i cpplab: ";
	try 
	{
		std::cout << vector1 * vector2 << "\n";
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << e.what();
	}
	
	std::vector<std::string> vector3 = { "a", "b", "c" };
	std::cout << vector1 * vector3; // nie zadziala

	struct CustomType {
		int value;
		CustomType(int v) : value(v) {}
	};
	std::vector<CustomType> vector4 = { CustomType(1), CustomType(2), CustomType(3) };
	std::cout << vector1 * vector4; // nie zadziala

	std::cout << "\n";


    //Zadanie 2
    std::vector<int> vector_i = { 2, 4, 3, 1 };
    std::vector<float> vector_f = { 2.2f, 4.4f, 3.3f, 1.1f };

    print_vector(vector_i);
    auto vector_i_output = as_sorted_view(vector_i); 
    print_pointer_vector(vector_i_output);

    std::cout << "\n";

    print_vector(vector_f);
    auto vector_f_output = as_sorted_view(vector_f);
    print_pointer_vector(vector_f_output);

    std::cout << "\n";


    //Zadanie 3    
    forward_list<int> list;
    list.push_front(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
	list.pop_front();
	list.pop_back();

    std::cout << "original: ";
    list.print();

    list.reverse();
    std::cout << "reversed: ";
    list.print();
}
