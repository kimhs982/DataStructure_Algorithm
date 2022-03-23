#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

#include <cmath>

int main()
{
	int input;
	cout << "n = ";
	cin >> input;		// n(입력의 크기)을 직접 입력 받음
	
	int* a = new int[input];		// input만큼 배열을 동적할당, int형 배열
	int* b = new int[input];		// input만큼 배열을 동적할당, int형 배열
	int* c = new int[input];		// input만큼 배열을 동적할당, int형 배열
	unsigned int* mat_storage = new unsigned int[pow(input, 3)];		// input^3만큼 배열을 동적할당, unsigned int형 배열

	for (int i = 0; i < input; i++)		// 각각의 배열을 초기화
	{
		a[i] = i + 1;
		b[i] = i + 2;
		c[i] = i + 3;
	}

	system_clock::time_point start = system_clock::now();		// 측정 시작

	int index = 0;
	for (int i = 0; i < input; i++)		// n^3번 for루프를 돌면서 곱함
		for (int j = 0; j < input; j++)
			for (int k = 0; k < input; k++)
				mat_storage[index++] = a[i] * b[j] * c[k];

	system_clock::time_point end = system_clock::now();		// 측정 종료
	nanoseconds nano_time = end - start;		// ns단위로 시간 측정

	cout << "n^3(Cubic complexity) 소요 시간 = " << nano_time.count() << "ns" << endl;

	delete[] a;		// 동적할당 된 배열 메모리 공간 해제
	delete[] b;		// 동적할당 된 배열 메모리 공간 해제
	delete[] c;		// 동적할당 된 배열 메모리 공간 해제
	delete[] mat_storage;		// 동적할당 된 배열 메모리 공간 해제

	return 0;
}