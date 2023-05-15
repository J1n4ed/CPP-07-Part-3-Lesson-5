// template functions header

#pragma once

#include <vector>
#include <algorithm>

namespace jinx
{

template<class T>
T my_sqr(T element)
{
	return element * element;
}

template<class T>
std::vector<T>& my_sqr(std::vector<T>& element)
{
	std::transform(element.begin(), element.end(), element.begin(), [](T i) -> T { return i * i; });

	return element;
}

} // END OF jinx