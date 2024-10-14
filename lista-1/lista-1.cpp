#include <iostream>
#include "lista_1.h"


int main()
{
	//Zadanie 1
	auto comp = [](auto a, auto b) { return a < b; };

	std::cout << "Typ int: " << my_max(5, 6, comp) << "\n";
	std::cout << "Typ float: " << my_max(3.14f, 3.2f, comp) << "\n";
	std::cout << "Typ double: " << my_max(3.14 , 3.2, comp) << "\n\n";


	//Zadnie 2
	std::vector<int> vector_i = { 1, 5, 3, 2, 4 };
	std::vector<float> vector_f = { 1.1f, 1.5f, 1.3f, 1.2f, 1.4f };

	insertion_sort(vector_i);
	print_vector(vector_i);

	insertion_sort(vector_f);
	print_vector(vector_f);


	//Zadanie 3
	std::cout << "\n";

	cpplab::vector<int> vector;

	//dodanie elementów
	vector.push_back(2);
	vector.push_back(4);
	vector.push_back(8);
	vector.push_back(16);
	vector.push_back(32);
	vector.push_back(64);

	std::cout << "Stworzenie nowego wektora poprzez dodawanie elementow, wektor = ";
	print_vector(vector);

	//usunięcie elementu
	vector.pop_back();
	std::cout << "Usuniecie ostatniego elementu, wektor = ";
	print_vector(vector);

	//odczytanie wartości
	std::cout << "Odczytanie wartosci, wektor[0] = " << vector[0] << "\n";

	//zmiana wartości
	vector[0] = 1;
	std::cout << "Zmiana wartosci, wektor[0] = " << vector[0] << "\n";

	//typ danych wektora
	std::cout << "Typ danych wektora: " << vector.data_type() << "\n";

	//obliczenie ilocznu sklalarnego
	std::cout << "Iloczyn skalarny wektora std:: i cpplab:: = " << vector_i * vector << "\n";

	//std::cout << "vector size: " << vector.size() << "\nvector capacity: " << vector.capacity() << "\n";
}
