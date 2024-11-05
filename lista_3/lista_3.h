#pragma once
#include <vector>
#include <algorithm>

template<typename T> 
void print_vector(std::vector<T> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (i == vector.size() - 1) std::cout << vector[i];
		else std::cout << vector[i] << ", ";
	}
	std::cout << "\n";
}

template<typename T>
std::vector<T> as_sorted_view(std::vector<T> vector)
{
	std::sort(vector.begin(), vector.end());

	return vector;
}

template<typename T> 
struct Node
{
	T data;
	std::unique_ptr<Node> next;
};

template<typename T>
class forward_list
{
private:
	std::unique_ptr<Node<T>> head;

public:
	forward_list() : head(nullptr)

	void push_back(T value)

	void print()

	void reverse()
};
