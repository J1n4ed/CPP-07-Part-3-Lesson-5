// main()

#include "..\headers\funct.hpp"
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	// VARIABLES

	std::vector<int> vect { 4, 1, 3, 6, 25, 54 };
	jinx::Functor fun;

	// BODY

	fun(vect);

	std::cout << "[IN]: ";

	for (int i : vect)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	std::cout << "[OUT]: get_sum() = " << fun.get_sum() << '\n';
	std::cout << "OUT]: get_count() = " << fun.get_count() << '\n';

	// EXIT
	std::cout << std::endl;
	system("pause");
	return 0;
} // END OF main()