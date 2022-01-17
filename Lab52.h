#pragma once
class matrix2
{
private:
	int col;
	int row;
	int* element;

public:

	matrix2();
	matrix2(int i, int j);
	matrix2(int i, int j, const int* arr);

	~matrix2();

	matrix2(const matrix2& orig);

	void sum(int row, int col, const int* arr);
	bool sum(matrix2 second);

	bool mult(int row, int col, const int* arr);
	bool mult(matrix2 second);

	void input(int i, int j, bool flag);
	void input(int i, int j, const int* arr);

	void print();
};

