#include <iostream>
#include <fstream>

#include "BoyerMoore.h"

int main() {
	string text, pattern;

	ifstream search_object("RFC2616_modified.txt");

	if (search_object.is_open()) {
		// ������ ��ġ �����ڸ� ������ ������ �̵�
		search_object.seekg(0, ios::end);

		// ��ġ�� ����(=������ ũ��)
		int size = search_object.tellg();

		// ������ ũ��� ���ڿ��� ũ�⸦ ���Ҵ�
		text.resize(size);

		// ������ ��ġ �����ڸ� ������ �� ������ �ű�
		search_object.seekg(0, ios::beg);

		// ���� ��ü ������ �о� ���ڿ��� ����
		search_object.read(&text[0], size);
	}
	else
		cout << "������ ã�� �� �����ϴ�!\n";

	int rep = 1;
	while (rep) {
		cout << "�˻��� ������ �Է��ϼ��� : ";
		getline(cin, pattern);

		int pos, previous = 0;
		while (1) {
			pos = BMmatch(text, pattern, previous);
			if (pos != -1)
				cout << "������ �߻��� ��ġ : " << pos << '\n';
			else
				break;
			previous = pos + pattern.length();
		}
		cout << "[�ٽ� �˻�(1), ����(0)] : ";
		cin >> rep;
		cin.ignore();
	}
	cout << "Ž�� ����\n";

	return 0;
}