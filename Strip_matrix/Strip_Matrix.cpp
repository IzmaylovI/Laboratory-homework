#include "Strip_Matrix.h"

str_matrix::str_matrix()
{
	_len = 6;
	size = 3;
	width = 2;
	pMem = new int* [size];

	for (int i = 0; i < size; i++)
	{
		pMem[i] = new int[width] {};
	}

	int shag = size - (width - 1);
	int m = 0;

	for (int i = 0; i < size; i++)
	{

		if (i || width == 1)
		{
			for (int j = m; j < width; j++)
			{
				pMem[i][j] = i + j + 1;
			}
			if (i > shag)
			{
				m++;
			}
		}
		else
		{
			for (int j = 0; j < width - 1; j++)
			{
				pMem[i][j] = i + j + 1;
			}
		}
	}
}

str_matrix::str_matrix(int m_size, int m_width)
	: size(m_size)
	, width(m_width)
{
	_len = size * width;
	pMem = new int* [size];

	for (int i = 0; i < size; i++)
	{
		pMem[i] = new int[width] {};
	}

	int shag = size - (width - 1);
	int m = 0;

	for (int i = 0; i < size; i++)
	{

		if (i || width == 1)
		{
			for (int j = m; j < width; j++)
			{
				pMem[i][j] = i + j + 1;
			}
			if (i >= shag)
			{
				m++;
			}
		}
		else
		{
			for (int j = 0; j < width - 1; j++)
			{
				pMem[i][j] = i + j + 1;
			}
		}
	}
}


vector<int>  operator* (str_matrix& NEO, const int* q)
{
	vector<int> res(NEO.size, 0);
	int shag = NEO.size - NEO.width + 1;
	int m = 0;

	for (int i = 0; i < NEO.size; i++)
	{
		if (NEO.width == 1)
		{
			m = i;
		}
		if (NEO.width == 2 && i > 1)
		{
			m = i - 1;
		}

		if (i > 1 && i <= shag && NEO.width > 1)
		{
			m = i - 1;
		}
		if (i == shag && m == 0)
		{
			m++;
		}

		for (int j = 0, k = m; j < NEO.width; j++, k++)
		{
			res[k] += NEO[i][j] * q[m + j];
		}
	}

	return res;
}

int* str_matrix:: operator[](int index)
{

	return pMem[index];
}

const int* str_matrix::operator[](int index) const
{
	return pMem[index];
}

ostream& operator<<(ostream& out, str_matrix& A)
{
	for (int i = 0; i < A.size; i++)
	{
		for (int j = 0; j < A.width; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}


str_matrix:: ~str_matrix()
{
	for (int i = 0; i < size; i++)
	{
		delete[] pMem[i];
	}
	delete[] pMem;

	pMem = nullptr;
}