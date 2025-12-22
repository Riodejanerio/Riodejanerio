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
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
}; Node* head = nullptr;

void push(int x) {
    Node* temp = new Node(x);
    temp->next = head; 
    head = temp;
}

void top() {
	if (head == nullptr) {
		cout << "stack is empty" << nl;
		return;
	}
	cout << head->val << nl;
}
void pop() {
	if (head == nullptr) {
		cout << "stack underflow" << nl;
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
}



void solve () {

    // push means inserting new element at head
	push(1);
	push(2);
    // pop means deleting from head
    pop();
    pop();
    // top means showing the value of head
	top();
	pop();

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