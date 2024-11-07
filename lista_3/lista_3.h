#pragma once
#include <vector>
#include <algorithm>

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
	for (auto& x : vector)
	{
		std::cout << *x << " ";
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
private:
	std::unique_ptr<Node<T>> head;

public:
	forward_list() : head(nullptr) {}

	void push_back(T value)
	{
		auto newNode = std::make_unique<Node<T>>(value);
		if (!head)
		{
			head = std::move(newNode);
		}
		else
		{
			Node<T>* current = head.get();
			while (current->next)
			{
				current = current->next.get();
			}
			current->next = std::move(newNode);
		}
	}

	
	void print()
	{
		Node<T>* current = head.get();
		while (current)
		{
			std::cout << current->data << " -> ";
			current = current->next.get();
		}
		std::cout << "null\n";
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
