// #include <iostream>
// using namespace std;


// void main1( ) {
//     vector<int> intVector;
//     intVector.push_back(11);
//     vector<int>::iterator p1 = intVector.begin();
//     vector<int>::const_iterator p2 = intVector.begin();
//     *p1 = 123;
//     // *p2 = 123; // Not allowed
//     cout << (*p1) << endl;
//     // cout << (*p2) << endl;
// }


// void main2( ) {
//     vector<int> v;
//     vector<int>::iterator iter;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     for (iter = v.begin(); iter != v.end(); iter++){
//         cout << (*iter) << endl;
//         *iter = 4;
//     }
//     for (iter = v.begin(); iter != v.end(); iter++){
//         cout << (*iter) << endl;
//     }
// }

// int main() {
//     main2( );
// }
#include <iostream>

using namespace std;

class A {
protected:
    static int cc;
public:
    A() {
        cc++;
        cout << "cA" << endl;
    }
    ~A() {
        cc--;
        cout << "dA" << endl;
    }
};

class B : public A {
public:
    B() {
        cc += 2;
        cout << "cB" << endl;
    }
    ~B() {
        cc -= 2;
        cout << "dB" << endl;
    }
};

int A::cc = 0;

void main3() {
    A *a;         // L1
    B b;          // L2
    // C *c;       // L3
    // a = new B;  // L4
    // c = new C;  // L5
    // delete c;   // L6
}

int main() {
    main3();
    return 0;
}
