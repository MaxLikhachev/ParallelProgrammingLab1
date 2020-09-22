#pragma once
#include <cmath>

template <typename T>
T calculate(T a, T b) {
	// sin(a)^2 + cos(b])^3
	return pow(sin(a), 2) + pow(cos(b), 3);
}