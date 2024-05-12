#include <iostream>

#include "Matrix.h"

using namespace std;

int main()
{
	int n;
	cin >> n;

	while(n--)
	{
		char command;
		cin >> command;

		Matrix m1, m2;
		int temp1[3][3], temp2[3][3];
		switch (command) {
		case '+':	
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cin >> temp1[i][j];
				}
			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cin >> temp2[i][j];
				}
			}
			m1 = Matrix(temp1[0][0], temp1[0][1], temp1[0][2], 
			   			temp1[1][0], temp1[1][1], temp1[1][2],
			   			temp1[2][0], temp1[2][1], temp1[2][2]);
			m2 = Matrix(temp2[0][0], temp2[0][1], temp2[0][2], 
			   			temp2[1][0], temp2[1][1], temp2[1][2],
			   			temp2[2][0], temp2[2][1], temp2[2][2]);
			m1.add(m2);
			m1.print();
			break;
		case '*':		
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cin >> temp1[i][j];
				}
			}
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cin >> temp2[i][j];
				}
			}
			m1 = Matrix(temp1[0][0], temp1[0][1], temp1[0][2], 
			   			temp1[1][0], temp1[1][1], temp1[1][2],
			   			temp1[2][0], temp1[2][1], temp1[2][2]);
			m2 = Matrix(temp2[0][0], temp2[0][1], temp2[0][2], 
			   			temp2[1][0], temp2[1][1], temp2[1][2],
			   			temp2[2][0], temp2[2][1], temp2[2][2]);
			m1.multiple(m2);
			m1.print();
			break;
		case 'p':		
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cin >> temp1[i][j];
				}
			}
			m1 = Matrix(temp1[0][0], temp1[0][1], temp1[0][2], 
			   			temp1[1][0], temp1[1][1], temp1[1][2],
			   			temp1[2][0], temp1[2][1], temp1[2][2]);
			m1.print();
			break;
		case 't':		
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cin >> temp1[i][j];
				}
			}
			m1 = Matrix(temp1[0][0], temp1[0][1], temp1[0][2], 
			   			temp1[1][0], temp1[1][1], temp1[1][2],
			   			temp1[2][0], temp1[2][1], temp1[2][2]);
			m1.transpose();
			m1.print();
			break;

		default:
			cout << "wrong input!" << endl;
			break;
		}
	}

	return 0;
}