#include "p1_3_2.h"

int main() {
	auto data = build_array(1, 0u, 'a', 3.2f, false);		// �Լ��� ���޵� ���ڵ��� ��� float �ڷ������� ��ȯ
	//auto data2 = build_array(1, "Packt", 2.0);		// ��� ������ Ÿ���� �ϳ��� ���� Ÿ������ ��ȯ�� �� ����

	for (auto i : data)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}