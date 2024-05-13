// Nonrecursive Mergesort.cpp
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define ll long long

const int MAXN = 1000005;
const int INF = 1e9;
int num[MAXN], N, temp[MAXN];
int expand;

void solve(){
    for(int len = 1; len < expand; len *= 2){
        for(int j = 0; j < expand - len; j += 2 * len){
            ll lptr = j;
            ll rptr = j + len;
            ll cnt = 0;
            while((lptr < j + len) and (rptr < j + 2 * len)){
                if(num[lptr] <= num[rptr]){
                    temp[cnt] = num[lptr];
                    lptr++;
                    cnt++;
                }
                else{
                    temp[cnt] = num[rptr];
                    rptr++;
                    cnt++;
                }
            }
            while(lptr < j + len){
                temp[cnt] = num[lptr];
                lptr++;
                cnt++;
            }
            while(rptr < j + 2 * len){
                temp[cnt] = num[rptr];
                rptr++;
                cnt++;
            }
            for(int k = 0; k < cnt; k++){
                num[j+k] = temp[k];
            }
        }
    }
}
signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    expand = 1;
    while(expand <= N) expand *= 2;
    for(int i = N; i < expand; i++){
        num[i] = INF;
    }
    solve();
    for(int i = 0; i < N; i++){
        cout << num[i] << " ";
    }
}
// 13
// 7 5 18 5 1 13 7 11 15 3 8 6 1