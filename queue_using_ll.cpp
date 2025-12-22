#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
using ll = long long;
using vin = vector<int>;
using vll = vector<ll>;
#define FastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


class Node{
public:
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {}
}; 
Node* front = nullptr;
Node* rear = nullptr;

void enqueue(int x) {
	Node* temp = new Node(x);
	if (!temp) {
		cout << "Heap Overflow" << endl;
        return;
	}
	if (front == nullptr) {
		front = rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}
void dequeue() {
	if (front == nullptr) {
		cout << "Queue underflow" << nl;
		return;
	}
	Node* temp = front;
	front = front->next;

	if (front == nullptr) {
		rear = nullptr;	
	}
	delete temp;
}

void top() {
	if (front == nullptr) {
		cout << "Queue is Empty!" << nl;
		return;
	}
	cout << front->val << nl;
}


void solve () {
    
    enqueue(23);
    enqueue(34);
    dequeue();
    dequeue();
    top();
    

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