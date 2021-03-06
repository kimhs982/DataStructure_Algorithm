//1.3
/*#include <iostream>
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
	//for (auto element : arr)
		//std::cout << element << ' ';
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
}*/

//1.4
/*#include <iostream>
#include <vector>

int main() {
	//std::vector<int> vec;
	//std::vector<int> vec = { 1, 2, 3, 4, 5 };
	//std::vector<int> vec(10);
	//std::vector<int> vec(10, 5);

	//std::vector<int> vec = { 1, 2, 3, 4, 5 };
	//vec.insert(vec.begin(), 0);

	//std::vector<int> vec;
	//vec.push_back(1);
	//vec.push_back(2);
	//vec.insert(vec.begin(), 0);
	//vec.insert(find(vec.begin(), vec.end(), 1) , 4);

	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vec.pop_back();
	vec.erase(vec.begin());
	vec.erase(vec.begin() + 1, vec.begin() + 4);

	return 0;
}*/

//1.5
#include <forward_list>
#include <iostream>

int main() {
	//std::forward_list<int> fwd_list = { 1, 2, 3 };
	//fwd_list.push_front(0);
	//auto it = fwd_list.begin();
	//fwd_list.insert_after(it, 5);
	//fwd_list.insert_after(it, 6);

	std::forward_list<int> fwd_list = { 1, 2, 3, 4, 5 };
	fwd_list.pop_front();
	auto it = fwd_list.begin();
	fwd_list.erase_after(it);
	fwd_list.erase_after(it, fwd_list.end());

	//std::forward_list<int> list1 = { 23, 0, 1, -3, 34, 32 };
	//list1.sort();
	//list1.sort(std::greater<int>());

	std::forward_list<int> list1 = { 2, 53, 1, 0, 4, 10 };
	list1.reverse();

	list1 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list1.sort();
	list1.unique();

	list1.unique([](int a, int b) {return (b - a) < 2; });

	return 0;
}