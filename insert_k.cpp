#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
using ll = long long;
using vin = vector<int>;
using vll = vector<ll>;
#define FastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Node {
    int data;
    Node *next;
} *head = nullptr, *last = nullptr;


Node* insert(Node* head, int pos, int x) {
    Node *t, *p;
    if (pos == 0) {
        t = new Node;
        t->data = x;
        t->next = head;
        head = t;
        if (last == nullptr) {
            last = t;
        }
    }
    else {
        p = head;
        int cnt = 0;
        while(p) {
            p = p->next;
            cnt++;
            if (cnt == pos - 1) {
                break;
            }
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;

        if (p == last) {
            last = t;
        }
    }
    return head;
}

void solve() {
    
    head = insert(head, 0, 34);
    head = insert(head, 0, 45);
    head = insert(head, 1, 23);


    Node *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    FastIO();
    solve();
    return 0;
}
