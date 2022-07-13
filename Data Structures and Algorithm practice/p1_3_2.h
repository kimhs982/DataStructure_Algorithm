// p37 ~ p39, ���߿� �����ϰ� �� �ٽú���!
#ifndef P1_3_2_H
#define P1_3_2_H

#include <array>
#include <iostream>
#include <type_traits>

template <typename ... Args>
auto build_array(Args&& ... args)->std::array<typename std::common_type<Args ... >::type, sizeof ... (args)>
{
	using commonType = typename std::common_type<Args ...>::type;
	return { std::forward<commonType>((Args&&)args) ... };
}

#endif