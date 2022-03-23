#include <iostream>
#include <chrono>

int fibonacci(int);

int main()
{
	int input;
	std::cout << "n = ";
	std::cin >> input;

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	
	fibonacci(input);

	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::nanoseconds nano_time = end - start;

	std::cout << "�Ǻ���ġ ����(2^n, Exponential complexity) �ҿ� �ð� = " << nano_time.count() << "ns" << std::endl;

	return 0;
}

int fibonacci(int n)
{
	if (n <= 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}