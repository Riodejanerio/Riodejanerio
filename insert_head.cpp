#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
using ll = long long;
using vin = vector<int>;
using vll = vector<ll>;
#define FastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

class Node {
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};
Node *head = nullptr;

void inserthead(int n) {

    Node *newitem = new Node(n);
    newitem->next = head;
    head = newitem;

}

void solve () {
    
    inserthead(34);
    inserthead(53);
    inserthead(55);

    Node *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }

}

int main() {
    FastIO();
    int t = 1;
    //cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}