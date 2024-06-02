#include "Vector.h"

void Vector::append(int element)
{
    // Append an element to the vector
    vec.push_back(element);
}

void Vector::clear()
{
    // Clear the vector
    vec.clear();
}

void Vector::print() const
{
    // Print the elements of the vector
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void Vector::heapify(int n, int i) {
    int large = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && vec[left] > vec[large])
        large = left;

    if (right <= n && vec[right] > vec[large])
        large = right;

    if (large != i) {
        swap(vec[i], vec[large]);
        heapify(n, large);
    }
}

void Vector::heapSort()
{
    // TODO: Perform heap sort on the vector
    //
    // Note: You can add other function like 'heapify()' to do this sorting algorithm
    // int n = vec.size();

    int n = vec.size();

    // change to 1-base
    vec.insert(vec.begin(), 0); 

    for (int i = n / 2; i >= 1; i--)
        heapify(n, i);

    for (int i = n; i > 1; i--) {
        swap(vec[1], vec[i]); 
        heapify(i - 1, 1);   
    }
    
    // delete addtional element
    vec.erase(vec.begin());
}