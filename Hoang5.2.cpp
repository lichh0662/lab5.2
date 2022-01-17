#include "Lab52.h"
#include <iostream>
#include <ctime>

matrix2::matrix2()
{
	row = 0;
	col = 0;
	element = nullptr;
}

matrix2::~matrix2()
{
	if (this->element != nullptr)
		delete[] this->element;
}

matrix2::matrix2(int i, int j)
{
	this->row = i;
	this->col = j;
	element = new int[row * col];
	for (int k = 0; k < row * col; k++)
		element[k] = 0;
}

matrix2::matrix2(int i, int j, const int* arr)
{
	this->row = i;
	this->col = j;
	element = new int[row * col];
	for (int k = 0; k < row * col; k++)
		element[k] = arr[k];
}

matrix2::matrix2(const matrix2& orig)
{
	this->row = orig.row;
	this->col = orig.col;

	if (orig.element != nullptr)
		this->element = new int[this->row * this->col];
	else this->element = nullptr;

	if (this->element != nullptr)
		for (int i = 0; i < this->row * this->col; i++)
			this->element[i] = orig.element[i];
}

void matrix2::sum(int row, int col, const int* arr)
{
	if ((row * col) != (this->row * this->col))
	{
		std::cout << "\nMatrices dont equal\n";
		return;
	}

	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->element[i] + arr[i];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << "\t"; //<<i * this->col + j <<": "
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool matrix2::sum(matrix2 second)
{
	if ((this->row != second.row) && (this->col != second.col))
	{
		std::cout << "\nmatrix sizes are not equal\n";
		return false;
	}
	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->element[i] + second.element[i];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return true;
}

bool matrix2::mult(int row, int col, const int* arr)
{
	if (this->col != row)
	{
		std::cout << "\nFirst col dont equal second row\n";
		return false;
	}

	int* res = new int[this->row * col];
	int i, j, k;

	for (i = 0; i < this->row * col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * col + j] += this->element[i * this->col + k] * arr[k * col + j];
		}
	}

	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < col; j++)
			std::cout << res[i * col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;

	return true;
}

bool matrix2::mult(matrix2 second)
{
	if (this->col != second.row)
	{
		std::cout << "\nFirst col dont equal second row\n";
		return false;
	}

	int* res = new int[this->row * second.col];
	int i, j, k;

	for (i = 0; i < this->row * second.col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * second.col + j] += this->element[i * this->col + k] * second.element[k * second.col + j];
		}
	}

	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
			std::cout << res[i * second.col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;

	return true;
}

void matrix2::input(int i, int j, bool flag)
{
	srand((unsigned)time(0));
	this->row = i;
	this->col = j;
	if (this->element != nullptr)
		delete[]this->element;
	this->element = new int[this->row * this->col];
	if (flag)
		for (int k = 0; k < this->row * this->col; k++)
			element[k] = 1 + rand() % 20;
	else for (int k = 0; k < this->row * this->col; k++)
		std::cin >> this->element[k];
}

void matrix2::input(int i, int j, const int* arr)
{
	this->row = i;
	this->col = j;
	if (this->element != nullptr)
		delete[]this->element;
	this->element = new int[this->row * this->col];
	for (int k = 0; k < this->row * this->col; k++)
		this->element[k] = arr[k];
}

void matrix2::print()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << this->element[i * this->col + j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
