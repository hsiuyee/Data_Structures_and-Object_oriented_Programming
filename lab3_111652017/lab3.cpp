#include <iostream>
#include <fstream>

#include "ConnectFour.h"

using namespace std;

int main()
{
	// TODO: Read the input from the "Sample_Input.txt" file
	
	string fileName;
	cout << "input the file name:\n";
	cin >> fileName;
	ifstream inputFile(fileName);

	int n; // Read the number of games from file
	inputFile >> n;
	while (n--)
	{
		ConnectFour connectFour;
		int cnt = 0;
		// TODO: Play Connect Four
		for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                int column;
                inputFile >> column;
                connectFour.Place(column - 1, cnt);
				// cout << "i: " << i << " " << " j: " << column << "\n";
				cnt++;
            }
			// cout << "\n";
        }

		// Print the result
		cout << "\n";
		connectFour.PrintBoard();
		connectFour.PrintWinner();
	}

    inputFile.close();

	return 0;
}