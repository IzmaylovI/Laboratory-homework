#include <iostream>
#include "matrix.h"
#include <vector>


#ifndef  STRIP_MATRIX
#define  STRIP_MATRIX


class str_matrix
{
private:
	int size;       // Размерность матрицы 
	int width;      // Ширина ленточной матрицы 
	int _len;       // Длина массива 
	int **pMem;     // Массив для хранения элементов ленточной матрицы 
public:
	str_matrix();
	str_matrix(int m_size, int m_tape);

	
	int* operator[](int index);
	const int* operator[](int index) const;
	friend ostream& operator<<(ostream& out, str_matrix& A);
	friend vector<int> operator* (str_matrix& NEO, const int* q);
	~str_matrix();
};

#endif // ! STRIP_MATRIX

