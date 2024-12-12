#include <iostream>
#include "BST.h"
#include "unique_ptr.h"
#include "dratewka.h"

int main()
{
    //Zadanie 1
    BST<int> tree;
    tree.insert(1);
    tree.insert(10);
    tree.insert(4);
    tree.insert(50);
    tree.insert(2);
    tree.insert(100);
    tree.insert(7);

    tree.print_in_order();

    std::cout << "\n";


    //Zadanie 2
    cpplab::unique_ptr<int> pointer(new int(1));
    std::cout << "wartosc ptr = " << *pointer << "\n";

    if (pointer) 
        std::cout << "ptr nie jest pusty\n";

    cpplab::unique_ptr<int> pointer2 = std::move(pointer);

    std::cout << "wartosc ptr 2 po przeniesieniu = " << *pointer2 << "\n";

    pointer2.reset(new int(2));
    std::cout << "wartosc ptr 2 po resecie = " << *pointer2 << "\n";

    pointer = new int(1);
    std::cout << "przed zamiana: wartosc ptr = " << *pointer << ", ptr 2 = " << *pointer2 << "\n";
    pointer.swap(pointer2);
    std::cout << "po zamianie: wartosc ptr = " << *pointer << ", ptr 2 = " << *pointer2 << "\n";

    std::cout << "\n";


    //Zadanie 3 
    int N = 3;
    int W = 50;
    std::vector<int> prices = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int max_price = dratewka(N, W, prices, weights);
    std::cout << "Maksymalna cena = " << max_price << "\n";
    
}
