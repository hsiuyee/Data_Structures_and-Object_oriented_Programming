#include <iostream>
using namespace std;

class Shape{
public:
    Shape () {}
    Shape(int id) {

    }
    virtual void printf() const {
        cout << "S" << "\n";
    }
};

class Rectangle: public Shape{
public:
    Rectangle() { }
    Rectangle(int id){

    }
    virtual void printf() const{
        cout << "R" << endl;
    }
};

void displayobj(Shape &g){
    Shape *p = &g;
    static_cast<Rectangle*>(p) -> printf();
}

class Y{
protected:
    int a;
};

int main() {
    Rectangle x;
    Shape y;
    // displayobj(x);
    // displayobj(y);
    Y *g = new Y;
    displayobj(*((Shape*)g));
}
