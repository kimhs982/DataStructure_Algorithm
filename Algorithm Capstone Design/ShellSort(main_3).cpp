#include <ctime>
#include <cstdlib>
#include "ShellSort.h"

int main()
{
	clock_t start, end;
	double result;
	srand(unsigned int(time(NULL)));		// 현재 시간을 seed 값으로 설정
	int** arr = new int* [5];
	arr[0] = new int[100000];		// size가 100,000인 배열
	arr[1] = new int[500000];		// size가 500,000인 배열
	arr[2] = new int[1000000];		// size가 1,000,000인 배열
	arr[3] = new int[5000000];		// size가 5,000,000인 배열
	arr[4] = new int[10000000];		// size가 10,000,000인 배열

	// 각각의 배열을 1~100 사이의 임의의 값으로 초기화(중복 허용)
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

	// 소수점 2째자리까지 표현
	cout << fixed;
	cout.precision(2);

	// 각 입력별 정렬소요 시간 및 정렬 결과 출력
	start = clock();
	ShellSort3(arr[0], 100000);
	end = clock();
	result = double(end) - double(start);
	cout << "증가식: 5h +1, 감소식: h/5 쉘 정렬 실행 시간 (N = 100000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort(arr[0], 100000);

	start = clock();
	ShellSort3(arr[1], 500000);
	end = clock();
	result = double(end) - double(start);
	cout << "증가식: 5h +1, 감소식: h/5 쉘 정렬 실행 시간 (N = 500000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort(arr[1], 500000);

	start = clock();
	ShellSort3(arr[2], 1000000);
	end = clock();
	result = double(end) - double(start);
	cout << "증가식: 5h +1, 감소식: h/5 쉘 정렬 실행 시간 (N = 1000000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort(arr[2], 1000000);

	start = clock();
	ShellSort3(arr[3], 5000000);
	end = clock();
	result = double(end) - double(start);
	cout << "증가식: 5h +1, 감소식: h/5 쉘 정렬 실행 시간 (N = 5000000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort(arr[3], 5000000);

	start = clock();
	ShellSort3(arr[4], 10000000);
	end = clock();
	result = double(end) - double(start);
	cout << "증가식: 5h +1, 감소식: h/5 쉘 정렬 실행 시간 (N = 10000000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort(arr[4], 10000000);

	for (int i = 0; i < 5; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}