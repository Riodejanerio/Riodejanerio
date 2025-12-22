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
Node* last = nullptr;


void insertfirst(int x) {
	Node *newitem = new Node(x);
	if (last == nullptr) {
		last = newitem;
		newitem->next = last;
	}
	else {
		newitem->next = last->next;
		last->next = newitem;
	}
}
void insertlast(int x) {
	Node* newitem = new Node(x);
	if (last == nullptr) {
		last = newitem;
		newitem->next = last;
	}
	else {
		newitem->next = last->next;
		last->next = newitem;
		last = newitem;
	}
}

void printList() {
    if (last == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* p = last->next;  // first node
    do {
    	cout << p->val << " ";
    	p = p->next;
    } while(p != last->next);
    

    cout << endl;
}


void solve () {

    insertfirst(1);
    insertfirst(2);
    insertfirst(3);
    insertfirst(4);

    insertlast(5);
    insertlast(6);
    insertlast(7);
    insertlast(8);

    printList();

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