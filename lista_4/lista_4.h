#pragma once
#include <vector>
#include <utility>

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
			:m_Capacity(vec.m_Capacity), m_Size(vec.m_Size), data(new T[vec.m_Capacity])
		{
			std::cout << "konstruktor kopiujacy\n";
			std::copy(&vec.data[0], &vec.data[0] + m_Size, &data[0]);
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
				if (m_Capacity < vec.m_Size)
				{
					delete[] data;
					m_Capacity = vec.m_Capacity;
					data = new T[m_Capacity];
				}

				m_Size = vec.m_Size;
				std::copy(&vec.data[0], &vec.data[0] + m_Size, &data[0]);
			}
			return *this;
		}

		vector& operator = (vector&& vec) noexcept
		{
			std::cout << "operator przenoszacy\n";
			if (this != &vec)
			{
				delete[] data;
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

		template<typename... Args>
		T& emplace_back(Args&&... args)
		{
			if (m_Capacity == 0)
				alloc(2);

			if (m_Size >= m_Capacity)
				alloc(m_Capacity + m_Capacity / 2);

			data[m_Size] = T(std::forward<Args>(args)...);
			return data[m_Size++];
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

struct Pixel
{
	int red = 0, green = 0, blue = 0;
	Pixel() = default;
	Pixel(int value) : red(value), green(value), blue(value) {};
	Pixel(int r, int g, int b): red(r), green(g), blue(b) {};
};

template<typename T>
void print_vector(const cpplab::vector<T>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i == vector.size() - 1) std::cout << vector[i];

		else std::cout << vector[i] << ", ";
	}
	std::cout << "\n";
}
template<>
void print_vector(const cpplab::vector<Pixel>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i].red << ", " << vector[i].green << ", " << vector[i].blue;
		std::cout << "\n";
	}
}
