#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

void countingSort(int arr[], int arr_size, int range) {
	int* temp = new int[arr_size];		// ���ĵ� ���¸� �ӽ÷� ������ temp[]
	int* count = new int[range]();		// count[] ����, ��� 0���� �ʱ�ȭ

	// ������ ������ ���� count[]�� ����
	for (int i = 0; i < arr_size; i++)
		count[arr[i]]++;

	// ���Ұ� �� ��ġ ���
	for (int i = 2; i <= range; i++)
		count[i] += count[i - 1];

	for (int i = arr_size - 1; i >= 0; i--) {
		temp[count[arr[i]] - 1] = arr[i];		// arr[]�� ���Ҹ� temp[]�� �̸� ���� ��ġ�� �̵�
		count[arr[i]]--;		// count[]�� ���� 1 ����
	}

	// temp[]�� a[]�� �̵�
	for (int i = 0; i < arr_size; i++)
		arr[i] = temp[i];

	delete[] temp;
	delete[] count;
}

#endif