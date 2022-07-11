#include "p1_3_1.h"

int main()
{
	int nStudents;
	std::cout << "1�� �л� ���� �Է��ϼ���: ";
	std::cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++)
	{
		std::string name;
		int standard;
		std::cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ���: ";
		std::cin >> name >> standard;
		class1[i] = student{ name, standard };
	}

	// �迭���� ū �ε����� �л��� ����
	try
	{
		// �Ʒ� �ּ��� �����ϸ� ���α׷��� ������ �����մϴ�.
		//class1[nStudents] = student{ "John",8 };

		class1.at(nStudents) = student{ "John",8 };
	}
	catch (...)
	{
		std::cout << "���� �߻�!" << std::endl;
	}

	// ���� ����
	auto class2 = class1;
	std::cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string() << std::endl;

	// �� �б��� ���ļ� ���ο� ū �б��� ����
	auto class3 = class1 + class2;
	std::cout << "1�ݰ� 2���� ���� 3�� ����: " << class3.to_string() << std::endl;

	return 0;
}