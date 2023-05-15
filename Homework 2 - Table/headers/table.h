// table class

#pragma once

#include <iostream>

// ----------------------------------------------------------------------------------------------------------------------
namespace jinx

	// ----------------------------------------------------------------- ARRAY
{
	/*
	������ ��� ���������
	*/
	template<class T>
	class Array
	{
	public:
		// PUBLIC AREA		

		// Public methods

		void print()
		{
			for (int i = 0; i < _size; ++i)
			{
				std::cout << i << ' ';
			}
		}

		// Overloads

		const T & operator [] (int index) const
		{
			if (index >= 0 && index < _size)
				return _array[index];
		}

		T & operator [] (int index)
		{
			if (index >= 0 && index < _size)
				return _array[index];
		}
		// Constructors

		Array() = delete;

		Array(int size)
		{
			_size = size;
			_array = new T[_size]{ 0 };
		}

		// Destructor

		~Array()
		{
			delete[] _array;
			_array = nullptr;
		}

	protected:
		// PROTECTED AREA
	private:
		// PRIVATE AREA
		T * _array = nullptr;
		int _size = -1;
	};

	// ----------------------------------------------------------------- TABLE

	/*
	������� ��� ��������
	*/
	template<class T>
	class Table
	{
	public:
		// PUBLIC AREA

		// Public methods

		// ������ ���� ����������� ������� Size, ������������ ������ �������.

		void size(int & rows, int & cols) const
		{
			if (_rows != -1 && _cols != -1)
			{
				rows = _rows;
				cols = _cols;
			}
		}

		// Overloads

		// ������ ���� ����������� � ������������� ������ ��������� [], ������������� ������, � �������� ����� ����� ��������� �������� [].

		const Array<T> & operator [] (int index) const
		{
			if (index >= 0 && index < _rows)
				return *_table[index];
		}

		Array<T> & operator [] (int index)
		{
			if (index >= 0 && index < _rows)
				return *_table[index];
		}

		// �����, ����� �������� ����������� ����:
		// *cout << table[i][j]; *table[i][j] = value; .		

		// Constructors

		Table() = delete;

		// ������ ���� �����������, ���������� �� ����� ��� ����� ����� � ���������� ����� � �������� ��������������.

		Table(int rows, int cols)
		{
			_rows = rows;
			_cols = cols;

			_table = new Array<T> * [_rows];

			for (int i = 0; i < _rows; ++i)
			{
				_table[i] = new Array<T>(_cols);
			}
		}

		// Destructor

		~Table()
		{
			for (int i = 0; i < _rows; ++i) 
			{
				delete [] _table[i];
				_table[i] = nullptr;
			} // for (int i = 0; i < rows; ++i)
			
			_table = nullptr;
		}

	protected:
		// PROTECTED AREA

	private:
		// PRIVATE AREA

		Array<T> ** _table = nullptr;
		int _rows = -1;
		int _cols = -1;

	}; // END OF class Table

// ----------------------------------------------------------------------------------------------------------------------
} // END OF jinx