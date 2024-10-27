#include <vector>
#include <typeinfo>
#include <stdexcept> 
#include <string>

template<typename T, typename C>
inline T my_max(T a, T b, C comp)
{
	return comp(a, b) == 0 ? a : b;
}

template<typename T>
inline std::vector<T> insertion_sort(std::vector<T>& vector) 
{
	for (int i = 1; i < vector.size(); i++) 
	{
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

template<typename Vec>
inline void print_vector(const Vec& vector)
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
		size_t Size = 0;
		std::string value_type = typeid(T).name();

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
		vector() {}

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
			if(Size > 0)
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

		std::string data_type() 
		{
			return value_type;
		}

		~vector()
		{
			delete[] data;
		}
	};
}

template<typename Vec1, typename Vec2>
auto operator * (const Vec1& vector_1, const Vec2& vector_2)
{
	if (vector_1.size() != vector_2.size())
	{
		throw std::invalid_argument("Wektory roznego rozmiaru");
	}

	auto product = 0;

	for (size_t i = 0; i < vector_1.size(); i++)
	{
		product += vector_1[i] * vector_2[i];
	}

	return product;
}
