#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

#include <cmath>

int main()
{
	int input;
	cout << "n = ";
	cin >> input;		// n(�Է��� ũ��)�� ���� �Է� ����
	
	int* a = new int[input];		// input��ŭ �迭�� �����Ҵ�, int�� �迭
	int* b = new int[input];		// input��ŭ �迭�� �����Ҵ�, int�� �迭
	int* c = new int[input];		// input��ŭ �迭�� �����Ҵ�, int�� �迭
	unsigned int* mat_storage = new unsigned int[pow(input, 3)];		// input^3��ŭ �迭�� �����Ҵ�, unsigned int�� �迭

	for (int i = 0; i < input; i++)		// ������ �迭�� �ʱ�ȭ
	{
		a[i] = i + 1;
		b[i] = i + 2;
		c[i] = i + 3;
	}

	system_clock::time_point start = system_clock::now();		// ���� ����

	int index = 0;
	for (int i = 0; i < input; i++)		// n^3�� for������ ���鼭 ����
		for (int j = 0; j < input; j++)
			for (int k = 0; k < input; k++)
				mat_storage[index++] = a[i] * b[j] * c[k];

	system_clock::time_point end = system_clock::now();		// ���� ����
	nanoseconds nano_time = end - start;		// ns������ �ð� ����

	cout << "n^3(Cubic complexity) �ҿ� �ð� = " << nano_time.count() << "ns" << endl;

	delete[] a;		// �����Ҵ� �� �迭 �޸� ���� ����
	delete[] b;		// �����Ҵ� �� �迭 �޸� ���� ����
	delete[] c;		// �����Ҵ� �� �迭 �޸� ���� ����
	delete[] mat_storage;		// �����Ҵ� �� �迭 �޸� ���� ����

	return 0;
}