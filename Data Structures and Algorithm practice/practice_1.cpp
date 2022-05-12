#include <iostream>
#include <array>
#include <typeinfo>

template <size_t N>
void print(const std::array<int, N>&);

int main() {
	std::array<int, 10> arr1;

	arr1[0] = 1;
	std::cout << "arr1 배열의 첫 번째 원소: " << arr1[0] << std::endl;

	std::array<int, 4> arr2 = { 1,2,3,4 };
	std::cout << "arr2의 모든 원소: ";

	for (int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;

	std::array<int, 4> arr3 = { 1,2,3,4 };

	try
	{
		std::cout << arr3.at(3) << std::endl;
		std::cout << arr3.at(4) << std::endl;
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	std::array<int, 5> arr = { 1,2,3,4,5 };
	//print(arr);
	/*for (auto element : arr)
		std::cout << element << ' ';*/
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		//std::cout << typeid(it).name() << std::endl;
		auto element = (*it);
		std::cout << element << ' ';
	}
	std::cout << '\n';
	
	std::cout << arr.front() << std::endl;
	std::cout << arr.back() << std::endl;
	std::cout << *(arr.data() + 1) << std::endl;

	return 0;
}

template <size_t N>
void print(std::array<int, N>& arr)
{
	for (auto ele : arr)
		std::cout << ele << ", ";
}
