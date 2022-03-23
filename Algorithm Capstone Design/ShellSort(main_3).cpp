#include <ctime>
#include <cstdlib>
#include "ShellSort.h"

int main()
{
	clock_t start, end;
	double result;
	srand(unsigned int(time(NULL)));		// ���� �ð��� seed ������ ����
	int** arr = new int* [5];
	arr[0] = new int[100000];		// size�� 100,000�� �迭
	arr[1] = new int[500000];		// size�� 500,000�� �迭
	arr[2] = new int[1000000];		// size�� 1,000,000�� �迭
	arr[3] = new int[5000000];		// size�� 5,000,000�� �迭
	arr[4] = new int[10000000];		// size�� 10,000,000�� �迭

	// ������ �迭�� 1~100 ������ ������ ������ �ʱ�ȭ(�ߺ� ���)
	for (int i = 0; i < 100000; i++)
		arr[0][i] = rand() % 100 + 1;
	for (int i = 0; i < 500000; i++)
		arr[1][i] = rand() % 100 + 1;
	for (int i = 0; i < 1000000; i++)
		arr[2][i] = rand() % 100 + 1;
	for (int i = 0; i < 5000000; i++)
		arr[3][i] = rand() % 100 + 1;
	for (int i = 0; i < 10000000; i++)
		arr[4][i] = rand() % 100 + 1;

	// �Ҽ��� 2°�ڸ����� ǥ��
	cout << fixed;
	cout.precision(2);

	// �� �Էº� ���ļҿ� �ð� �� ���� ��� ���
	start = clock();
	ShellSort3(arr[0], 100000);
	end = clock();
	result = double(end) - double(start);
	cout << "������: 5h +1, ���ҽ�: h/5 �� ���� ���� �ð� (N = 100000): " << (result / CLOCKS_PER_SEC) << "��" << endl;
	checkSort(arr[0], 100000);

	start = clock();
	ShellSort3(arr[1], 500000);
	end = clock();
	result = double(end) - double(start);
	cout << "������: 5h +1, ���ҽ�: h/5 �� ���� ���� �ð� (N = 500000): " << (result / CLOCKS_PER_SEC) << "��" << endl;
	checkSort(arr[1], 500000);

	start = clock();
	ShellSort3(arr[2], 1000000);
	end = clock();
	result = double(end) - double(start);
	cout << "������: 5h +1, ���ҽ�: h/5 �� ���� ���� �ð� (N = 1000000): " << (result / CLOCKS_PER_SEC) << "��" << endl;
	checkSort(arr[2], 1000000);

	start = clock();
	ShellSort3(arr[3], 5000000);
	end = clock();
	result = double(end) - double(start);
	cout << "������: 5h +1, ���ҽ�: h/5 �� ���� ���� �ð� (N = 5000000): " << (result / CLOCKS_PER_SEC) << "��" << endl;
	checkSort(arr[3], 5000000);

	start = clock();
	ShellSort3(arr[4], 10000000);
	end = clock();
	result = double(end) - double(start);
	cout << "������: 5h +1, ���ҽ�: h/5 �� ���� ���� �ð� (N = 10000000): " << (result / CLOCKS_PER_SEC) << "��" << endl;
	checkSort(arr[4], 10000000);

	for (int i = 0; i < 5; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}