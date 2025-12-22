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
    Node(int x, Node* ptr) : val(x), next(ptr) {} 
}; 


Node* convertll(vin& arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;   
    }
    return head;
}

void print(Node* p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}

Node* removehead(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removelast(Node* head) {
    Node* temp = head;
    while( temp ->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removek(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp) {
        cnt++;
        if (cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeElement(Node* head, int element) {
    if (head == nullptr) return head;
    if (head->val == element) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp) {
        if (temp->val == element) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


Node* inserthead(Node* head, int x) {
    return new Node(x, head);
}

Node* insertlast(Node* head, int x) {
    if (head == nullptr) {
        return new Node(x);
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    Node* newval = new Node(x);
    temp->next = newval;
    return head;
}

Node* insertpos(Node* head, int val, int k) {

    if (head == nullptr) {
        if (k == 1) {
            return new Node(val);
        } else {
            return nullptr;
        }
    }

    if (k == 1) {
        return new Node(val, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp) {
        cnt++;
        if (cnt == k - 1) {
            Node* newval = new Node(val, temp->next);
            temp->next = newval;
            break;
        }

        temp = temp->next;
    }
    return head;

}

Node* insertBeforeValue(Node* head, int x, int value) {
    if (head->val == value) {
        return new Node(x, head);
    }
    Node* temp = head;
    while (temp->next) {
        if (temp->next->val == value) {
            Node* add = new Node(x, temp->next);
            temp->next = add;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void solve () {
        
    head = insertpos(head, 99, 1);
    head = insertBeforeValue(head, 2, 99);
    head = insertBeforeValue(head, 1, 2);
    head = removeElement(head, 99);

    print(head);

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