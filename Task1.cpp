#include <iostream>

template <typename T=int>
T** allocMatrix(T** m, int rows, int columns);

template <typename T>
void free_matrix(T** matrix, int rows, int columns);

void fill(int** matrix, int rows, int columns);
void print_matrix(int** matrix, int rows, int columns);

int main() {
	int n = 0;

	std::cout << "Enter matrix size:" << std::endl;
	std::cin >> n;

	int** matrix = NULL;
	matrix = allocMatrix(matrix, n, n);

	fill(matrix, n, n);

	std::cout << "Your matrix:" << std::endl;

	print_matrix(matrix, n, n);
	free_matrix(matrix, n, n);

	return 0;
}

void print_matrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			std::cout << matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void fill(int** matrix, int rows, int columns) {
	int ibeg = 0;
	int iend = 0;
	int jbeg = 0;
	int jend = 0;

	int fnum = 1;
	int i = 0;
	int j = 0;

	while (fnum <= rows * columns) {
		matrix[i][j] = fnum;

		if (i == ibeg && j < columns - jbeg - 1)
			++j;
		else if (j == columns - jend - 1 && i < rows - iend - 1)
			++i;
		else if (i == rows - iend - 1 && j > jbeg)
			--j;
		else
			--i;

		if ((i == ibeg + 1) && (j == jbeg) && (jbeg != columns - jend - 1)) {
			++ibeg;
			++iend;
			++jbeg;
			++jend;
		}

		++fnum;
	}
}

template <typename T>
T** allocMatrix(T** m, int rows, int columns)
{
	m = new T * [rows];

	for (int i = 0; i < rows; ++i)
		m[i] = new T[columns];

	return m;
}

template <typename T>
void free_matrix(T** matrix, int rows, int columns) {
	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];

	delete[] matrix;
}