//
//  main.cpp
//  Laboratorio2
//
//  Created by Lucho on 9/7/23.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <stdio.h>
using namespace std;
#define Tam 2000
void mulMat(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    vector<vector<int>> rslt(Tam,vector<int>(Tam));
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < Tam; i++) {
        for (int j = 0; j < Tam; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < Tam; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "Multiplicacion Clasica" << endl;
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " ns" << endl;

}
void multSeisBloques(vector<vector<int>> mat1, vector<vector<int>> mat2)
{
    vector<vector<int>>rslt(Tam, vector<int>(Tam));
    int ii, jj, kk, i, j, k, n, B;
    B = Tam/2;
    n = Tam;
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
    cout << "Seis Bloques" << endl;
    cout << "Elapsed time in nanoseconds: "
        << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()
        << " ns" << endl;
}
int main()
{
    vector<vector<int>> mat1(Tam, vector<int>(Tam));
    vector<vector<int>> mat2(Tam, vector<int>(Tam));
    for (int i = 0; i < Tam; i++)
        for (int j = 0; j < Tam; j++)
        {
            mat1[i][j] = 2;
            mat2[i][j] = 3;
        }
    mulMat(mat1, mat2);
    multSeisBloques(mat1, mat2);
    return 0;
}
