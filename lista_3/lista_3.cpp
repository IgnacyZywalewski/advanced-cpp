#include <iostream>
#include "Lista_3.h"

namespace cpplab
{
	template<typename T>
	class vector {

		T* data = nullptr;
		size_t capacity = 0;
		size_t Size = 0;

		void alloc(size_t new_capacity)
		{
			T* new_data = new T[new_capacity];

			if (new_capacity < Size)
			{
				Size = new_capacity;
			}

			for (size_t i = 0; i < Size; i++)
			{
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
			capacity = new_capacity;
		}


	public:
		using value_type = T;

		vector() {}

		~vector()
		{
			delete[] data;
		}

		const size_t size() const { return Size; }
		const size_t Capacity() const { return capacity; }

		void push_back(const T& value)
		{
			if (capacity == 0)
				alloc(2);

			if (Size >= capacity)
				alloc(capacity + capacity / 2);

			data[Size] = value;
			Size++;
		}

		void pop_back()
		{
			if (Size > 0)
			{
				Size--;
				data[Size].~T();
			}
		}

		T operator[](size_t index) const
		{
			return data[index];
		}

		T& operator[](size_t index)
		{
			return data[index];
		}
	};
}


int main()
{
    //Zadanie 1
	std::vector<float> vec1 = { 1.f, 2.f, 3.f };
	cpplab::vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);

	std::cout << "Iloczyn skalarny wektorow std i cpplab: " << vec1 * vec2 << "\n";
	
	std::vector<std::string> vec3 = { "a", "b", "c" };
	//std::cout << vec1 * vec3 << "\n";

	struct CustomType {
		int value;
		CustomType(int v) : value(v) {}
	};
	std::vector<CustomType> vec4 = { CustomType(1), CustomType(2), CustomType(3) };
	//std::cout << vec * vec4 << "\n";

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
