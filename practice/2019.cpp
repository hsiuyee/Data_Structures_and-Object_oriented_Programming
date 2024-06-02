#include <iostream>
#include <deque>
#include <istream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;


void main4(){
    unsigned char x[3]; unsigned short y; int z;
    fstream input;
    input.open("sc.txt", ios::in|ios::binary ); input.seekg(8, ios::beg);
    cout << input.tellg() << endl; // L1
    input.read(reinterpret_cast<char*>(&x[0]), sizeof(unsigned char));
    cout << input.tellg() << endl; input.seekg(-3, ios::cur); // L2
    input.read(reinterpret_cast<char*>(&x[1]), sizeof(unsigned char));
    cout << input.tellg() << endl; input.seekg(-6, ios::end); // L3
    input.read(reinterpret_cast<char*>(&y), sizeof(unsigned short));
    cout << "Hi " << input.tellg() << endl; input.seekg(2, ios::cur); // L4
    input.read(reinterpret_cast<char*>(&x[2]), sizeof(unsigned char));
    cout << input.tellg() << endl; input.seekg(-5, ios::end); // L5
    input.read(reinterpret_cast<char*>(&z), sizeof(z));
    cout << "x[0]: " << x[0] << "\n";
    cout << "x[1]: " << x[1] << "\n";
    cout << "x[2]: " << x[2] << "\n";
    cout << "y: " << y << "\n";
    cout << "z: " << z << "\n";

}
int main() {
    main4();
}


// template<typename TD = int> class X {
//     public:
//         TD a;
//         X() : a(0){}
//         X(TD a) : a(a) {}
//         X *operator*(const X& b){
//             X &c = new X;
//             c->a = (*this).a * b->a;
//             return (c);
//         }

// };

// int main1() {
//     X<> p(34);
//     X<> q(65);
//     cout << p.a * q.a << "\n";
// }

// class P {
// 	public: P( ) {
// 		c = 'P';
// 		cout << c << endl;
// 	}
// 	P(char c) {
// 		(*this).c = c;
// 	}
// 	void printf() const {
// 		cout << "\t" << c << endl;
// 	}
// 	char c;
// }
// ;
// class Q: public P {
// 	public: Q( ) {
// 		c = 'q';
// 	}
// 	Q (char c) {
// 		this->c = c;
// 		cout << c << endl;
// 	}
// 	virtual void printf() const {
// 		cout << "Q:" << "\t" << c << endl;
// 	}
// 	char c;
// }
// ;
// class R: public Q {
// 	public: R( ):Q('q') {
// 		cout << "c:" << P::c << endl;
// 	}
// 	R(char name): Q( ) {
// 		this->c = c;
// 		cout << c << endl;
// 	}
// 	virtual void printf() const {
// 		cout << "R:" << "\t" << P::c << endl;
// 	}
// }
// ;
// void main2( ) {
// 	R x;                // L1
//     cout << "\n------------------------\n";
// 	Q y('b');           // L2
//     cout << "\n------------------------\n";
// 	P z('c');           // L3
//     cout << "\n------------------------\n";
// 	Q *a = &x;
// 	a->printf( );       // L4
//     cout << "\n------------------------\n";
// 	a = &y;
// 	a->printf( );       // L5
// }

// class A {
// 	static int cc;
// 	public:
// 	A( ) {
// 		cc++;
// 		cout << "cA" << endl;
// 	}
// 	~A( ) {
// 		cc--;
// 		cout << "dA" << endl;
// 	}
// }
// ;
// class B: public A {
// 	public:
// 	B( ) {
// 		cc += 2;
// 		cout << "cB" << endl;
// 	}
// 	~B( ) {
// 		cc -= 2;
// 		cout << "dB" << endl;
// 	}
// }
// ;
// class C : public B {
// 	public:
// 	C( ) {
// 		cc += 3;
// 		cout << "cC" << endl;
// 	}
// 	~C( ) {
// 		cc -=3;
// 		cout << "dC" << endl;
// 	}
// }
// ;
// int A::cc = 0;

// void main3( ) {
// 	A *a;			// L1
// 	B b;			// L2
	// C *c;			// L3
	// a = new B;		// L4
	// c = new C;		// L5
	// delete c;		// L6
// }