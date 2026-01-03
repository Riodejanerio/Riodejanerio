#include <bits/stdc++.h>
#define nl '\n'
using namespace std;
using vin = vector<int>;

class Node {
public:
    int val;
    Node* next;
    Node* back;

    Node(int x) : val(x), next(nullptr), back(nullptr) {}
    Node(int x, Node* p, Node* t) : val(x), next(p), back(t) {}
};
Node* convertarray(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head) {
    Node *p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << nl;
}
// delete head 
Node* deletehead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* p = head;
    head = head->next;
    head->back = nullptr;
    p->next = nullptr;
    delete p;
    return head;
}
// delete tail
Node* deletetail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* p = head;
    while (p->next) {
        p = p->next;
    }
    Node* prev = p->back;
    prev->next = nullptr;
    p->back = nullptr;
    delete p;
    return head;
}
Node* deletekthelement(Node* head, int k) {
    Node* ptr = head;
    int cnt = 0;
    while(ptr) {
        cnt++;
        if (cnt == k) break;
        ptr = ptr->next;
    }
    if (ptr ->next == nullptr && ptr->back == nullptr) {
        return head;
    }
    else if (ptr->back == nullptr) {
        return deletehead(head);
    }
    else if (ptr->next == nullptr) {
        return deletetail(head);
    }
    else {
        Node* prev = ptr->back;
        Node* front = ptr->next;
        prev->next = front;
        front->back = prev;
        ptr->next = nullptr;
        ptr->back = nullptr;
    }
    return head;
}
// insert head
Node* insertHead(Node* head, int x) {
    Node* temp = new Node(x,head,nullptr);
    head->back = temp;
    temp->back = nullptr;
    return temp;
}
// insert at tail 
Node* inserttail(Node* head, int x) {
    Node* p = head;
    while(p->next) {
        p = p->next;
    }
    Node* temp = new Node(x);
    temp ->back = p;
    p->next = temp;

    return head;
}
// insert before k th element 
Node* insertbeforek(Node* head, int k, int x) {
    if (k == 1) {
        return insertHead(head,x);
    }
    int cnt = 0;
    Node* p = head;
    while(p) {
        cnt++;
        if (k == cnt) break;
        p = p->next;
    }
    
    Node* prev = p->back;
    Node* temp = new Node(x,p,prev);
    prev->next = temp;
    p->back = temp;
    return head;
}
Node* deleteEven(Node* head) {
    // delete head positions 
    while(head != nullptr && head->val % 2 ==0 ) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if (head == nullptr || head->next == nullptr) return head;
    Node* p = head;
    while(p->next != nullptr) {
        if (p->next->val % 2 == 0) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        else {
            p = p->next;
        }
    }
    return head;
}
// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next; // store next node
        current->next = previous;       // reverse the link
        previous = current;             // move previous forward
        current = nextNode;             // move current forward
    }

    return previous; // new head
}
// Function to reverse doubly linked list
Node* reverseDoubly(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        // Swap next and back
        temp = current->back;
        current->back = current->next;
        current->next = temp;

        // Move to next node (which is previous back)
        current = current->back;
    }
    // temp now points to old head's previous node, which is new head
    if (temp != nullptr) {
        head = temp->back;
    }
    return head;
}

void checkPalindrome(Node* head) {
    if (!head || !head->next) {
        cout << "YES\n";
        return;
    }

    // Step 1: Count the number of nodes
    int cnt = 0;
    Node* temp = head;
    while (temp) {
        cnt++;
        temp = temp->next;
    }

    // Step 2: Find middle
    int mid = cnt / 2;

    // Step 3: Push first half into stack
    stack<int> s;
    temp = head;
    for (int i = 0; i < mid; i++) {
        s.push(temp->val);
        temp = temp->next;
    }

    // Step 4: If odd length, skip middle node
    if (cnt % 2 != 0) temp = temp->next;

    // Step 5: Compare second half with stack
    while (temp) {
        if (temp->val != s.top()) {
            cout << "NO\n";
            return;
        }
        s.pop();
        temp = temp->next;
    }

    cout << "YES\n";
}


// Function to insert a number into sorted linked list
Node* insertSorted(Node* head, int num) {
    Node* newNode = new Node(num);

    // If list is empty or number is smaller than head
    if (!head || num < head->val) {
        newNode->next = head;
        return newNode;  // new node becomes head
    }

    Node* temp = head;

    // Traverse to find correct position
    while (temp->next && temp->next->val < num) {
        temp = temp->next;
    }

    // Insert new node after temp
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}