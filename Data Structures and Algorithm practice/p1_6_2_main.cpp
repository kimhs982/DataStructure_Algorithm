#include "p1_6_2.h"

int main()
{
	singly_ll sll = { 1, 2, 3 };
	sll.push_front(0);

	std::cout << "ù ��° ����Ʈ: ";
	for (auto i : sll)
		std::cout << i << ' ';
	std::cout << std::endl;

	auto sll2 = sll;
	sll2.push_front(-1);
	std::cout << "ù ��° ����Ʈ�� ������ ��, �� �տ� -1�� �߰�: ";
	for (auto i : sll2)
		std::cout << i << ' ';
	std::cout << std::endl;

	std::cout << "���� ���� �� ù ��° ����Ʈ: ";

	for (auto i : sll)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}