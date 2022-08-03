#include "p1_3_2.h"

int main() {
	auto data = build_array(1, 0u, 'a', 3.2f, false);		// 함수에 전달된 인자들이 모두 float 자료형으로 변환
	//auto data2 = build_array(1, "Packt", 2.0);		// 모든 데이터 타입을 하나의 공통 타입으로 변환할 수 없음

	for (auto i : data)
		std::cout << i << ' ';
	std::cout << std::endl;

	return 0;
}