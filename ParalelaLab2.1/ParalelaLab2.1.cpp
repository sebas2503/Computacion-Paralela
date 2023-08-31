// ParalelaLab2.1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <stdio.h>
using namespace std;

#define R1 4
#define C1 4
#define R2 4
#define C2 4

void mulMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
	vector<vector<int>> rslt(R1,vector<int>(C2));
    auto start = chrono::steady_clock::now();
	for (int i = 0; i < R1; i++) {
		for (int j = 0; j < C2; j++) {
			rslt[i][j] = 0;

			for (int k = 0; k < R2; k++) {
				rslt[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

    cout << "Multiplicacion Clasica" << endl;
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            cout << rslt[i][j] << "\t";
        }
        cout << endl;
    }
}
void multSeisBloques(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    vector<vector<int>>rslt(R1, vector<int>(C2));
    int ii, jj, kk, i, j, k, n, B;
    B = R1/2;
    n = R1;
    auto start2 = chrono::steady_clock::now();
    for (ii = 0; ii < n; ii += B) 
    {
        for (jj = 0; jj < n; jj += B)
        {
            for (kk = 0; kk < n; kk += B)
            {
                for (i = ii; i < ii + B; i++)
                {
                    for (j = jj; j < jj + B; j++) 
                    {
                        for (k = kk; k < kk + B; k++)
                        {
                            rslt[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }
            }
        }
    }
    auto end2 = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()
        << " ns" << endl;
    cout << "Seis Bloques" << endl;
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            cout << rslt[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> mat1(R1, vector<int>(C1));
    vector<vector<int>> mat2(R2, vector<int>(C2));
    for (int i = 0; i < R1; i++)
        for (int j = 0; j < C1; j++)
        {
            mat1[i][j] = 2+i;
            mat2[i][j] = 3+j;
        }
    mulMat(mat1, mat2);
    multSeisBloques(mat1, mat2);
    return 0;
}