#pragma once
#include <vector>

namespace cpplab
{
	template<typename T>
	class vector {

		T* data = nullptr;
		size_t m_Capacity = 0;
		size_t m_Size = 0;

		void alloc(size_t new_capacity)
		{
			T* new_data = new T[new_capacity];

			if (new_capacity < m_Size)
			{
				m_Size = new_capacity;
			}

			for (size_t i = 0; i < m_Size; i++)
			{
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
			m_Capacity = new_capacity;
		}


	public:
		vector() 
		{
			std::cout << "konstruktor domyslny\n";
		}

		vector(const vector& vec)
			:m_Capacity(vec.m_Capacity), m_Size(vec.m_Size)
		{
			std::cout << "konstruktor kopiujacy\n";
			data = new T[m_Capacity];
			if (vec.data != nullptr)
			{
				for (size_t i = 0; i < m_Size; i++)
				{
					data[i] = vec.data[i];
				}
			}

		}

		vector(vector&& vec) noexcept
			:data(vec.data), m_Size(vec.m_Size), m_Capacity(vec.m_Capacity)
		{
			std::cout << "konstruktor przenoszacy\n";
			vec.data = nullptr;
			vec.m_Size = 0;
			vec.m_Capacity = 0;
		}

		vector& operator = (const vector& vec)
		{
			std::cout << "operator kopiujacy\n";
			if (this != &vec)
			{
				alloc(vec.m_Capacity);
				m_Size = vec.m_Size;

				for (size_t i = 0; i < m_Size; i++)
				{
					data[i] = vec.data[i];
				}

			}
			return *this;
		}

		vector& operator = (vector&& vec) noexcept
		{
			std::cout << "operator przenoszacy\n";
			if (this != &vec)
			{
				data = vec.data;
				m_Size = vec.m_Size;
				m_Capacity = vec.m_Capacity;

				vec.data = nullptr;
				vec.m_Size = 0;
				vec.m_Capacity = 0;
			}
			return *this;
		}

		~vector()
		{
			std::cout << "destruktor\n";
			delete[] data;
		}

		using value_type = T;

		const size_t size() const { return m_Size; }
		const size_t capacity() const { return m_Capacity; }

		void push_back(const T& value)
		{
			if (m_Capacity == 0)
				alloc(2);

			if (m_Size >= m_Capacity)
				alloc(m_Capacity + m_Capacity / 2);

			data[m_Size] = value;
			m_Size++;
		}

		void pop_back()
		{
			if (m_Size > 0)
			{
				m_Size--;
				data[m_Size].~T();
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

template<typename T>
void print_vector(const T& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i == vector.size() - 1) std::cout << vector[i];
		
		else std::cout << vector[i] << ", ";
	}
	std::cout << "\n";
}
