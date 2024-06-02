#include <iostream>
#include <fstream>
#include <sstream>

#include "Time.h"

using namespace std;

void readFile(const char* filename)
{
	Time time1, time2;
	char op;

	// TODO: Read the data from the txt file.
	ifstream inFile(filename);
	// ofstream outFile("out.txt");
	string line;
	while(getline(inFile, line)){
		// cout << line << "\n";
		stringstream ss(line);
		ss >> time1 >> op >> time2;
		
		// cout << time1 << op << time2;

		if(op == '='){
			if(time1 == time2) cout << "True\n";
			else cout << "False\n";
		}
		else if(op == '!'){
			if(time1 != time2) cout << "True\n";
			else cout << "False\n";
		}
		else if(op == '+'){
			time1 = time1 + time2;
			cout << time1;
			// cout << time1 << op << time2;
		}
		else if(op == '-'){
			time1 = time1 - time2;
			cout << time1;
		}
	}
	inFile.close();
}

int main()
{
	// readFile("Sample_Input.txt");
	readFile("Hidden_Input.txt");

	return 0;
}