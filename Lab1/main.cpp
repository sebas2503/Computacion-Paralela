//
//  main.cpp
//  Lab1
//
//  Created by Lucho on 8/24/23.
//

#include <chrono>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 5000
int main()
{
    vector<vector<double>> A;
    vector<double>x;
    vector<double>y;
    for (int i = 0; i < MAX; i++)
    {
        // construct a vector of int
        vector<double> v;
        for (int j = 0; j < MAX; j++) {
            v.push_back(0);
        }
        A.push_back(v);
    }
    for (int i = 0; i < MAX; i++)
        x.push_back(0);
    for (int i = 0; i < MAX; i++)
        y.push_back(0);
    // Primera forma
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
    // Segunda forma
    auto start2 = chrono::steady_clock::now();
    for (int j = 0; j < MAX; j++)
    {
        for (int i = 0; i < MAX; i++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end2 = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count()
        << " ms" << endl;
}
