// QuickSort.cpp
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long

const int MAXN = 1000005;
const int INF = 1e9;
int num[MAXN], N, temp[MAXN];

void solve(int l, int r){
    if (l >= r) return;
    int pivot = num[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (num[i] < pivot) i++;
        while (num[j] > pivot) j--;
        if (i <= j) {
            swap(num[i], num[j]);
            i++;
            j--;
        }
    }
    solve(l, j);
    solve(i, r);
}
signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    solve(0, N-1);
    for(int i = 0; i < N; i++){
        cout << num[i] << " ";
    }
}
// 13
// 7 5 18 5 1 13 7 11 15 3 8 6 1