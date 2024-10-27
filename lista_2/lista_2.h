#pragma once

#include <vector>
#include <string>
#include <cctype>

template<typename T>
inline void print_vector(const std::vector<T>& vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];

		if (i != vector.size() - 1) std::cout << ", ";
		else std::cout << "\n";
	}
}

bool natural_compare(const std::string& vector_1, const std::string& vector_2)
{
	int i = 0, j = 0;
	
	while (i < vector_1.size() && j < vector_2.size())
	{
		if (std::isdigit(vector_1[i]) && std::isdigit(vector_2[j]))
		{
			int start_i = i, start_j = j;

			while (i < vector_1.size() && std::isdigit(vector_1[i]))
				i++;

			while (j < vector_2.size() && std::isdigit(vector_2[j]))
				j++;

			int num_1 = std::stoi(vector_1.substr(start_i, i - start_i));
			int num_2 = std::stoi(vector_2.substr(start_j, j - start_j));

			if (num_1 != num_2) {
				return num_1 > num_2;
			}
		}

		else
		{
			if (vector_1[i] != vector_2[j])
			{
				return vector_1[i] > vector_2[j];
			}
			i++;
			j++;
		}
	}

	return vector_1.size() > vector_2.size();
}

//porzadek leksykograficzny
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

//porzadek naturalny
template<>
inline std::vector<std::string> insertion_sort(std::vector<std::string>& vector)
{
	for (int i = 1; i < vector.size(); i++)
	{
		std::string key = vector[i];
		int j = i - 1;

		while (j >= 0 && natural_compare(vector[j], key))
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = key;
	}

	return vector;
}


template<int n>
constexpr unsigned long long factorial()
{
	if constexpr (n == 0 || n == 1) return 1;

	else return n * factorial<n - 1>();
}


template<typename T>
inline void print_all(T arg)
{
	std::cout << arg;
}

template<typename T, typename... Args>
inline void print_all(T first, Args... rest)
{
	std::cout << first << " ";
	print_all(rest...);
	
}
