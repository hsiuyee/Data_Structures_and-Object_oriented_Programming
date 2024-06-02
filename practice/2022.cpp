#include <iostream>
#include <deque>
#include <istream>
#include <fstream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// void s(const char *msg)
// {
//     cout << msg << endl;
// }

// class X {
// public:
//     X() { s("X()"); }
//     ~X() { s("~X()"); }
// };

// class Y : public X {
// public:
//     Y() { s("Y()"); }
//     ~Y() { s("~Y()"); }
// };

// class Z : public Y {
// public:
//     Z() { s("Z()"); }
//     ~Z() { s("~Z()"); }
// };

// void t01() { X a; }
// void t02() { Z b; }
// void t03() { Z *w = new Z; }

// void main1()
// {
//     // t01(); // L1
//     // t02(); // L2
//     t03(); // L3
// }

// int test(int n, int d) {
//     int s = 0;
//     for (int i = 0; i < n; i += d) {
//         if (i % 2 == 1) {
//             s = s + 1;
//         }
//     }
//     return s;
// }

// template<typename T = int>
// int go(int n, int d) {
//     T m = 0;
//     int i = n;
//     while (i > 0) {
//         if (i % 2 != 1) {
//             m = m + 1;
//         }
//         i = i - d;
//     }
//     return m / 2;
// }

// void main8() {
//     // cout << test(1, 2) << endl; // L1
//     // cout << go(1, 2) << endl; // L2
//     // cout << test(10, 3) << endl; // L3
//     cout << go<double>(1234, 6) << endl; // L4
// }

// class A {
// private:
//     int a;
// protected:
//     int b;
// public:
//     int c;
// };

// class B : public A {
// private:
//     int x;
// protected:
//     int y;
// public:
//     int c;
//     void foo() {
//         // a = 0; // L1
//         b = 1; // L2
//         c = 2; // L3
//     }
// };

// class C : protected B {
//     public:
//         void f01() {
//             A w;
//             // w.a = 0; // L4
//             // w.b = 1; // L5
//             w.c = 2; // L6
//         }
// };

// void main1() {
//     C u;
//     u.f01();
// }

void u(const char *msg) {
    cout << msg << endl;
}

class W {
public:
    static int t;
    W() { u("W()"); t = t + 1; }
    W(int w) { u("W(int)"); }
    void f01() { u("W::f01"); }
    virtual void f02() { u("W::f02"); }
};

int W::t = 0;

class X : public W {
public:
    X() { u("X()"); }
    X(int w) { u("X(int)"); }
    void f01() { u("X::f01"); }
    void f02() override { u("X::f02"); }
};

class Y : public W {
public:
    Y() { u("Y()"); }
    Y(int w) { u("Y(int)"); }
    virtual void f01() { u("Y::f01"); }
    virtual void f02() override { u("Y::f02"); }
};

void f() {
    X x;
    Y y;
    W *p;
    
    // x.f01(); // L1
    // y.f02(); // L2

    p = &y;
    // p->f01(); // L3
    // p->f02(); // L4

    p = &x;
    // p->f01(); // L5
    // p->f02(); // L6

    Y *yp;
    yp = dynamic_cast<Y*>(p); // L7
    if(yp == nullptr){
        cout << "null\n";
    }
    X s(10); // L8
    // other instructions
}

int main7() {
    f();
    return 0;
}
int main() {
    main7();
}
