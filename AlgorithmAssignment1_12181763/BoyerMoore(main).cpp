#include <iostream>
#include <fstream>

#include "BoyerMoore.h"

int main() {
	string text, pattern;

	ifstream search_object("RFC2616_modified.txt");

	if (search_object.is_open()) {
		// 파일의 위치 지정자를 파일의 끝으로 이동
		search_object.seekg(0, ios::end);

		// 위치를 읽음(=파일의 크기)
		int size = search_object.tellg();

		// 파일의 크기로 문자열의 크기를 재할당
		text.resize(size);

		// 파일의 위치 지정자를 파일의 맨 앞으로 옮김
		search_object.seekg(0, ios::beg);

		// 파일 전체 내용을 읽어 문자열에 저장
		search_object.read(&text[0], size);
	}
	else
		cout << "파일을 찾을 수 없습니다!\n";

	int rep = 1;		// 반복 여부를 저장
	while (rep) {
		cout << "검색할 패턴을 입력하세요 : ";
		getline(cin, pattern);		// 공백(' ')을 포함하여 검색할 문자열을 입력받음

		int pos, previous = 0;		// pattern이 발생한 위치를 저장하는 pos와 이전에 검색한 pattern의 위치를 저장하는 previous
		while (1) {
			pos = BMmatch(text, pattern, previous);
			if (pos != -1)		// text에서 pattern과 일치하는 부분을 발견한 경우
				cout << "패턴이 발생한 위치 : " << pos << '\n';
			else
				break;
			previous = pos + pattern.length();		// pattern이 발생한 위치에 pattern의 길이를 더해 previous에 저장
		}
		cout << "[다시 검색(1), 종료(0)] : ";
		cin >> rep;
		cin.ignore();		// cin을 통해 rep를 입력 받으면 마지막 개행문자('\n')가 버퍼에 남아 while() 문을 반복할 경우 위의 getline()에 개행문자('\n')가 자동으로 입력됨 -> 버퍼에 남아있는 개행문자('\n')를 지워줌
	}
	cout << "탐색 종료\n";

	return 0;
}