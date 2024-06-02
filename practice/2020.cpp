#include <iostream>
#include <deque>
#include <istream>
#include <fstream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// class X {
// public:
//     int x;
//     string n;

//     X() { 
//         n = "z"; 
//         x = 0; 
//     }

//     X(string n, int x) { 
//         this->n = n; 
//         this->x = x; 
//     }

//     X(const X &a) {
//         this->n = "copy of\t" + a.n;
//         this->x = a.x;
//     }

//     ~X() { 
//         // cout << n << endl; 
//     }

//     X& operator=(const X &a) {
//         this->n = "assign\t" + a.n + "\tto\t" + this->n;
//         return *this;
//     }

//     void p() const {
//         cout << "X:" << "\t" << n << "\t" << x << endl;
//     }
// };

// void q03_1(X x) {
//     x.p();
// }

// void q03_2(const X &x) {
//     x.p();
// }

// void main5() {
//     X x1;
//     x1.p();               // L1
//     X x2 = x1;
//     x2.p();               // L2

//     X x3("x3", 2);
//     x3.p();               // L3

//     (x3 = x1).p();        // L4

//     q03_1(x2);            // L5
//     q03_1(X("good", 5));  // L6
//     q03_2(*(new X("hello", 6)));  // L7
//     cout << "-----\n";
// }

int main10() {
    unsigned short a[] = {0x4321, 0x5678, 0xcdef, 0x89ab};
    unsigned char *r = (unsigned char*) a;
    unsigned short *p = a;
    unsigned int *q = (unsigned int*) a;

    // Values of the required elements
    cout << "a[3]: " << hex << a[3] << endl;
    cout << "(r+2)[2]: " << hex << (int)*(r + 2 + 2) << endl;
    cout << "(p+1)[2]: " << hex << *(p + 1 + 2) << endl;
    cout << "q[1]: " << hex << q[1] << endl;

    // Assign 0x56 to the second element of r
    r[1] = 0x56;

    return 0;
}


int main() {
    main10();
}

// // class P{
// //     public:
// //         int c;
// //         static int d;
// //         P() {c = 5;};
// // };
// // int P::d = 0;
// // void main4(){
// //     P x;
// //     x.c = 1;
// //     cout << x.c << "\n";
// // }

// // class X{
// //     public:
// //         int a, b;
// //         X() {
// //             a = -1;
// //             b = 1;
// //         }
// //         X(int a, int b = 3){
// //             this->a = a;
// //             this->b = b;
// //         }
// // };

// void main1(){
//     X x, y(7);
//     cout << "x.a: " << x.a << "\n";
//     cout << "y.b: " << y.b << "\n";
// }