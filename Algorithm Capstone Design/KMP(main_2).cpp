#include <iostream>
using namespace std;

#include "KMP.h"

int main()
{
	string Text = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";
	string Pattern = "algorithm";

	int pos, previous = 0, temp = 0;
	int M = Pattern.length(), N = Text.length();
	while (1)
	{
		pos = KMP(Pattern, Text, previous);		// Text의 previous 위치부터 Pattern을 찾음. 발견한 Pattern의 index를 pos에 저장
		temp = pos + M;
		if (temp <= N)		// Text 문자열의 끝 부분에 도달했는지 확인
			cout << "패턴이 발생한 위치 : " << pos << '\n';
		else
			break;
		previous = temp;
	}

	cout << "탐색 종료\n";

	return 0;
}