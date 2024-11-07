#include <iostream>
#include "Lista_3.h"

int main()
{
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
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << "original: ";
    list.print();

    list.reverse();
    std::cout << "reversed: ";
    list.print();
}
