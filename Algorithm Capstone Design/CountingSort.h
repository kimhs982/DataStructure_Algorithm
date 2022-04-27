#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

void countingSort(int arr[], int arr_size, int range) {
	int* temp = new int[arr_size];		// 정렬된 상태를 임시로 저장할 temp[]
	int* count = new int[range]();		// count[] 생성, 모두 0으로 초기화

	// 원소의 개수를 세어 count[]에 저장
	for (int i = 0; i < arr_size; i++)
		count[arr[i]]++;

	// 원소가 들어갈 위치 계산
	for (int i = 2; i <= range; i++)
		count[i] += count[i - 1];

	for (int i = arr_size - 1; i >= 0; i--) {
		temp[count[arr[i]] - 1] = arr[i];		// arr[]의 원소를 temp[]의 미리 계산된 위치로 이동
		count[arr[i]]--;		// count[]의 값을 1 감소
	}

	// temp[]를 a[]로 이동
	for (int i = 0; i < arr_size; i++)
		arr[i] = temp[i];

	delete[] temp;
	delete[] count;
}

#endif