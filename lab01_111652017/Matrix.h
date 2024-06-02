#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
public:
	int m_matrix[3][3];

	Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                m_matrix[i][j] = 0;
            }
        }
    }
    Matrix(int a, int b, int c, int d, int e, int f, int g, int h, int i){
		m_matrix[0][0] = a;
		m_matrix[0][1] = b;
		m_matrix[0][2] = c;
		m_matrix[1][0] = d;
		m_matrix[1][1] = e;
		m_matrix[1][2] = f;
		m_matrix[2][0] = g;
		m_matrix[2][1] = h;
		m_matrix[2][2] = i;
	}

	void print();
	void add(Matrix m);
	void multiple(Matrix m);
	void transpose();
};

#endif // __MATRIX_H__