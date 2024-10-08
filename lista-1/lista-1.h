#include <vector>
#include <typeinfo>
#include <stdexcept> 

template<typename T, typename C>
inline T my_max(T a, T b, C comp)
{
	if (comp(a, b) == 0) return a;

	return b;
}

template<typename T>
inline std::vector<T> insertion_sort(std::vector<T>& vector) 
{
	for (int i = 1; i < vector.size(); i++) {
		T key = vector[i];
		int j = i - 1;

		while (j >= 0 && vector[j] > key)
		{
			vector[j + 1] = vector[j];
			j--;
		}

		vector[j + 1] = key;
	}

	return vector;
}

template<typename T>
inline void print_vector(std::vector<T>& vector) 
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];

		if (i != vector.size() - 1) std::cout << ", ";
		else std::cout << "\n";
	}
}


namespace cpplab
{
	template<typename T>
	class vector {

		T* data = nullptr;
		size_t capacity = 0;
		size_t size = 0;
		const char* value_type = typeid(T).name();

		void alloc(size_t new_capacity)
		{
			T* new_data = new T[new_capacity];

			if (new_capacity < size)
				size = new_capacity;

			for (size_t i = 0; i < size; i++)
				new_data[i] = data[i];

			delete[] data;
			data = new_data;
			capacity = new_capacity;
		}


	public:
		vector() {}

		const size_t Size() { return size; }
		const size_t Capacity() { return capacity; }

		void push_back(const T& value)
		{
			if (capacity == 0) {
				alloc(2);
			}

			if (size >= capacity)
				alloc(capacity + capacity / 2);

			data[size] = value;
			size++;
		}

		void pop_back() 
		{
			if(size > 0)
				size--;
		}

		T operator[](size_t index) const{
			return data[index];
		}

		T& operator[](size_t index) {
			return data[index];
		}

		const char* data_type() {
			return value_type;
		}

		void print_vector() 
		{
			for (size_t i = 0; i < size; i++) 
			{
				std::cout << data[i];

				if (i != size - 1) std::cout << ", ";
				else std::cout << "\n";
			}
		}


		template<typename C>
		C operator*(std::vector<C>& vector_std)
		{
			if (vector_std.size() != size) {
				throw std::invalid_argument("Wektory roznego rozmiaru");
			}

			C product = 0;
			for (size_t i = 0; i < size; i++){
				product += data[i] * vector_std[i];
			}

			return product;
		}
	};
}

