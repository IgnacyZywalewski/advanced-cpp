#include <vector>
#include <string>
#include <algorithm>

bool compare(const std::string& vector_1, const std::string& vector_2)
{
	//TODO


	return vector_1.size() < vector_2.size();
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

template<>
inline std::vector<std::string> insertion_sort(std::vector<std::string>& vector)
{
	for (int i = 1; i < vector.size(); i++)
	{
		std::string key = vector[i];
		int j = i - 1;

		while (j >= 0 && compare(vector[j], key))
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = key;
	}

	return vector;
}

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
