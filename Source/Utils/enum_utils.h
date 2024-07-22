#ifndef ENUM_UTILS_H
#define ENUM_UTILS_H

#include <iostream>

template <typename EnumType>
inline constexpr int enumToInt(EnumType t) {
	static_assert(std::is_enum<EnumType>::value, "Exception: Type must be an enum");
	return static_cast<int>(t);
}



#endif