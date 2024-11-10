#pragma once

#include <vector>
#include <type_traits>
#include <algorithm>
#include <memory>

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
		vector() {}

		~vector()
		{
			delete[] data;
		}

		using value_type = T;

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


template<typename Vec>
concept is_vector = requires(Vec v, size_t i) 
{
	{ v.size() } -> std::convertible_to<size_t>;
	{ v[i] };
};

template<typename T1, typename T2>
concept is_arithmetic = requires(T1 a, T2 b)
{
	{ a * b };
	{ a += b };
};

template<is_vector Vec1, is_vector Vec2>
requires is_arithmetic<typename Vec1::value_type, typename Vec2::value_type>
auto operator * (const Vec1& vector_1, const Vec2& vector_2)
{
	if (vector_1.size() != vector_2.size())
	{
		throw std::invalid_argument ("Wektory roznego rozmiaru\n");
	}

	auto dot_product = 0.0;

	for (size_t i = 0; i < vector_1.size(); i++)
	{
		dot_product += (vector_1[i] * vector_2[i]);
	}

	return dot_product;
}


template<typename T>
inline void print_vector(const std::vector<T>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i == vector.size() - 1) std::cout << vector[i];
		else std::cout << vector[i] << ", ";
	}
	std::cout << "\n";
}

template<typename T>
inline void print_pointer_vector(const std::vector<T*>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i == vector.size() - 1) std::cout << *vector[i];
		else std::cout << *vector[i] << ", ";
	}
	std::cout << "\n";
}

template<typename T>
inline std::vector<const T*> as_sorted_view(const std::vector<T>& vector)
{
	size_t n = vector.size();
	std::vector<const T*> pointer_vector(n);

	for (size_t i = 0; i < n; i++)
	{
		pointer_vector[i] = &vector[i];
	}

	std::sort(pointer_vector.begin(), pointer_vector.end(), [](const T* a, const T* b) { return *a < *b; });

	return pointer_vector;
}


template<typename T> 
struct Node
{
	T data;
	std::unique_ptr<Node> next;

	Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class forward_list
{
	std::unique_ptr<Node<T>> head;

public:
	forward_list() : head(nullptr) {}

	void push_front(T value)
	{
		auto new_node = std::make_unique<Node<T>>(value);
		new_node->next = std::move(head);
		head = std::move(new_node);
	}

	void push_back(T value)
	{
		auto new_node = std::make_unique<Node<T>>(value);
		if (!head)
		{
			head = std::move(new_node);
		}
		else
		{
			Node<T>* current = head.get();
			while (current->next)
			{
				current = current->next.get();
			}
			current->next = std::move(new_node);
		}
	}

	void pop_front()
	{
		if (head)
		{
			head = std::move(head->next);
		}
	}

	void pop_back()
	{
		if (!head)
		{
			return;
		}
		else if (!head->next)
		{
			head = nullptr;
			return;
		}
		else
		{
			Node<T>* current = head.get();
			while (current->next && current->next->next)
			{
				current = current->next.get();
			}
			current->next = nullptr;
		}
	}

	
	void print()
	{
		Node<T>* current = head.get();
		while (current)
		{
			std::cout << current->data;
			if (current->next)
			{
				std::cout << " -> ";
			}
			current = current->next.get();
		}
		std::cout << "\n";
	}

	
	void reverse()
	{
		std::unique_ptr<Node<T>> prev = nullptr;
		while (head)
		{
			std::unique_ptr<Node<T>> next = std::move(head->next);
			head->next = std::move(prev);
			prev = std::move(head);
			head = std::move(next);
		}
		head = std::move(prev);
	}
};
