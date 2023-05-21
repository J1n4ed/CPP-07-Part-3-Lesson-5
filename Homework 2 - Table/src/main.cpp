// main function

#include "..\headers\table.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	// VARIABLES

	int rows = 5;
	int cols = 7;

	jinx::Table<int> table(rows, cols);
	jinx::Table<int> tableCopy(rows - 1, cols + 1);

	// BODY

	std::cout << "table size:\nRows = " << rows << ", " << "cols = " << cols << '\n';

	std::cout << "Table created:\n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << table[i][j] << ' ';
		}

		std::cout << '\n';
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			table[i][j] = 1;
		}
	}
	
	std::cout << "\n\n";
	std::cout << "Table filled with 1s:\n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << table[i][j] << ' ';
		}

		std::cout << '\n';
	}

	std::cout << "\n\n";
	std::cout << "table[0][0] = 4:\n";
	table[0][0] = 4;
	std::cout << table[0][0] << '\n';
	std::cout << "\n\n";

	int newRows = 0;
	int newCols = 0;
	std::cout << "New size variables:\nnewRow = " << newRows << ", " << "newCols = " << newCols << '\n';

	table.size(newRows, newCols);

	std::cout << "Called size() method for table:\nnewRow = " << newRows << ", " << "newCols = " << newCols << '\n';

	// COPY TEST

	std::cout << "\n\n----------- COPY TEST --------------\n\n";

	std::cout << "Making a copy of table to tableCopy" << '\n';

	tableCopy = table;

	table[1][1] = 99;

	int copyRows = 0;
	int copyCols = 0;

	tableCopy.size(copyRows, copyCols);

	std::cout << "Called size() method for tableCopy:\ncopyRow = " << copyRows << ", " << "copyCols = " << copyCols << '\n';

	std::cout << "tableCopy print:\n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << tableCopy[i][j] << ' ';
		}

		std::cout << '\n';
	}

	// ADDITION TESTS

	std::cout << "\n\n----------- ADDITIONAL TEST --------------\n\n";

	std::cout << "\nTest 1: Array<int>a1 = Array<int>a2...\n";
	jinx::Array<int> a1(5);
	jinx::Array<int> a2(3);
	a1 = a2;
	std::cout << "\nTest 1: passed.\n";

	std::cout << "\nTest 2: Array<int>22(a11)...\n";
	jinx::Array<int> a11(5);
	jinx::Array<int> a22(a11);
	std::cout << "\nTest 2: passed.\n";

	std::cout << "\nTest 3: table1 = table2...\n";
	jinx::Table<int> table1(2, 2);
	jinx::Table<int> table2(4, 4);
	table1 = table2;
	std::cout << "\nTest 3: passed.\n";

	std::cout << "\nTest 4: table1[0][0] = 100, cout table2[0][0]...\n";
	table2[0][0] = 5;
	table1[0][0] = 100;
	std::cout << "\ntable2[0][0] = " << table2[0][0] << std::endl;
	std::cout << "\nTest 4: passed.\n";

	// EXIT

	std::cout << std::endl;
	system("pause");
	return 0;
} // END OF main()