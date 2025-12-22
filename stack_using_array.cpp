#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
using ll = long long;
using vin = vector<int>;
using vll = vector<ll>;
#define FastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define MAX 1000000
int sz = -1;
int stk[MAX];

void push(int x) {
    if (sz == MAX-1) {cout << "stack overflow" << nl; return; }
    sz++;
    stk[sz] = x;
}

void top() {
    if(sz == -1) {
        cout << "Empty!" << nl;
        return;
    }
    cout << stk[sz] << nl;
}
void pop() {
    if (sz == -1) {
        cout << "stack underflow" <<nl;
        return;
    }
    sz--;
}

void solve () {

    
}

int main() {
    FastIO();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}