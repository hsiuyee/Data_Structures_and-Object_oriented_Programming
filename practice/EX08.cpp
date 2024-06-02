#include <iostream>
using namespace std;

void h() {
	//throw(28);
}
void k() {
	h();
	cout << "here" << endl;
	throw(string("call k()"));
}

void g() {
	try {
		k( );
	}
	catch(int num) {
		cout << "Num:" << num << endl;
	}
	catch( string &e ) {
		cout << "Error:" << e << endl;
	}
}

int main1( ) {
	try {
		g( );
	}
	catch( int e ) {
		cout << "Error:" << e << endl;
	}
	g();
	system("pause");
	return 0;
}

int f1() {
	try {
		throw runtime_error("Exception in f1");
	}
	catch (exception& ex) {
		cout << "Exception caught in function f1" << endl;
		cout << ex.what() << endl;
		throw;
		// Rethrow the exception
	}
}
void main2() {
	try {
		f1();
	}
	catch (exception& ex) {
		cout << "Exception caught in function main" << endl;
		cout << ex.what() << endl;
	}
}

int main() {
    main2( );
}