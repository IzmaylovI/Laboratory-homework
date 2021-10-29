#include <iostream>
#include "Strip_Matrix.h"
#include <vector>
#include "Matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m;

	cout << "VVedite razmer lentocny matricy i shirinu matricy" << endl;
	cin >> n >> m;
	str_matrix A(n,m);

	cout << "\nVid hranenia letochnoy matricy: \n\n" << endl;
	cout << A << endl;

	int* r = new int[n];
	for (int i = 0; i < n; i++)
	{
		r[i] = 1;
	}

	cout << "\n\n";
	cout << "Umnozhaem lentochnuy matricu na:\n\n" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << r[i] << endl;
	}

	cout << "\n\n";
	cout << "result:\n\n" ;
	
	vector <int> M(A * r);

	for (int i = 0; i < n; i++)
	{
		cout << M[i] << endl;
	}
}