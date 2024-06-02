#include "Matrix.h"

#include <iostream>

using namespace std;

void Matrix::print()
{
	cout << "[";
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << m_matrix[i][j];
			if(i * 3 + j != 8) cout << ", ";
		}
	}
	cout << "]" << '\n';
}

void Matrix::add(Matrix m)
{
	for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_matrix[i][j] += m.m_matrix[i][j];
        }
    }
}

void Matrix::multiple(Matrix m)
{
	int result[3][3] = {{0}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += m_matrix[i][k] * m.m_matrix[k][j];
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_matrix[i][j] = result[i][j];
        }
    }
}

void Matrix::transpose() 
{
	int temp[3][3];
	for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            temp[j][i] = m_matrix[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m_matrix[i][j] = temp[i][j];
        }
    }
}