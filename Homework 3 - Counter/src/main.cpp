// main()

#include "..\headers\funct.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

int main(int argc, char** argv)
{
	// VARIABLES

	std::vector<int> vect { 4, 1, 3, 6, 25, 54 };
	std::list<int> list{ 3, 7, 2, 5, 30, 44 };
	jinx::Functor funVect;
	jinx::Functor funList;

	// BODY

	// ----------------- VECTOR

	std::cout << "\n\n-------------- std::vector ---------------\n\n";

	funVect = std::for_each(vect.begin(), vect.end(), funVect);

	std::cout << "[IN](Vector): ";

	for (int i : vect)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	std::cout << "[OUT](Vector): get_sum() = " << funVect.get_sum() << '\n';
	std::cout << "[OUT](Vector): get_count() = " << funVect.get_count() << '\n';

	// ------------------ LIST

	std::cout << "\n\n-------------- std::list ---------------\n\n";

	funList = std::for_each(list.begin(), list.end(), funList);

	std::cout << "[IN](List): ";

	for (int i : list)
	{
		std::cout << i << ' ';
	}

	std::cout << '\n';

	std::cout << "[OUT](List): get_sum() = " << funList.get_sum() << '\n';
	std::cout << "[OUT](List): get_count() = " << funList.get_count() << '\n';

	// EXIT
	std::cout << std::endl;
	system("pause");
	return 0;
} // END OF main()