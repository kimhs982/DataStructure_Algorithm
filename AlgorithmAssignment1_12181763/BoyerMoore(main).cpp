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

	int rep = 1;		// �ݺ� ���θ� ����
	while (rep) {
		cout << "�˻��� ������ �Է��ϼ��� : ";
		getline(cin, pattern);		// ����(' ')�� �����Ͽ� �˻��� ���ڿ��� �Է¹���

		int pos, previous = 0;		// pattern�� �߻��� ��ġ�� �����ϴ� pos�� ������ �˻��� pattern�� ��ġ�� �����ϴ� previous
		while (1) {
			pos = BMmatch(text, pattern, previous);
			if (pos != -1)		// text���� pattern�� ��ġ�ϴ� �κ��� �߰��� ���
				cout << "������ �߻��� ��ġ : " << pos << '\n';
			else
				break;
			previous = pos + pattern.length();		// pattern�� �߻��� ��ġ�� pattern�� ���̸� ���� previous�� ����
		}
		cout << "[�ٽ� �˻�(1), ����(0)] : ";
		cin >> rep;
		cin.ignore();		// cin�� ���� rep�� �Է� ������ ������ ���๮��('\n')�� ���ۿ� ���� while() ���� �ݺ��� ��� ���� getline()�� ���๮��('\n')�� �ڵ����� �Էµ� -> ���ۿ� �����ִ� ���๮��('\n')�� ������
	}
	cout << "Ž�� ����\n";

	return 0;
}